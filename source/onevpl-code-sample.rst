.. _onevpl-code-sample:

oneVPL Code Sample
==================


oneVPL exposes a minimal basic interface suitable for most core video
processing use cases. This interface consists of a class that exposes
three core methods: SetConfig (use for configuring options), GetState
(use to control the main read/write loop), and DecodeFrame (use to
read/write data).


::


   #include "vpl/vpl.hpp"
   #define BUFFER_SIZE 1024 * 1024
   int main(int argc, char* argv[]) {
     if (argc != 2) {
       printf("usage: %s [h264 input file]\n", argv[0]);
       printf("example: %s content/cars_1280x720.h264\n", argv[0]);
       return 1;
     }
     // Create decoder, default device is GPU
     vpl::Decode decoder(VPL_FOURCC_H264);
     // Set output color format
     decoder.SetConfig(VPL_PROP_DST_FORMAT, VPL_FOURCC_RGBA);
     // Set output resolution
     VplVideoSurfaceResolution output_size = {352, 288};
     decoder.SetConfig(VPL_PROP_OUTPUT_RESOLUTION, output_size);
     // initialize
     uint8_t *pbs=new uint8_t[BUFFER_SIZE];
     FILE* fInput = fopen(argv[1], "rb");
     if (!fInput) {
       printf("could not open input file '%s'\n", argv[1]);
       return 1;
     }
     VplFile* fOutput = vplOpenFile("out_352x288.rgba", "wb");
     vplm_mem* image = nullptr;
     bool bdrain_mode = false;
     // -----------
     // MAIN LOOP
     // ----------
     // Loop until done.  Decode state of END_OF_OPERATION or
     // ERROR indicates loop exit.
     vplWorkstreamState decode_state = VPL_STATE_READ_INPUT;
     for (; decode_state != VPL_STATE_END_OF_OPERATION &&
            decode_state != VPL_STATE_ERROR;
          decode_state = decoder.GetState()) {
       // read more input if state indicates buffer space
       // is available
       uint32_t bs_size = 0;
       if ((decode_state == VPL_STATE_READ_INPUT) && (!bdrain_mode)) {
         bs_size = (uint32_t)fread(pbs, 1, BUFFER_SIZE, fInput);
       }
       if (bs_size == 0 || decode_state == 
         VPL_STATE_INPUT_BUFFER_FULL) {
         bdrain_mode = true;
       }
       // Attempt to decode a frame. If more data is needed read again
       if (bdrain_mode)
         image = decoder.DecodeFrame(nullptr, 0);
       else
         image = decoder.DecodeFrame(pbs, bs_size);
       if (!image) continue;
       // If decode resulted in a frame of output write it to file
       vplWriteData(fOutput, image);
       printf(".");
       fflush(stdout);
     }
     printf("\n");
     // cleanup
     fclose(fInput);
     vplCloseFile(fOutput);
     delete[] pbs;
     return 0;
   }


To compile the code, use one of the following commands:


-  On Linux:


   ::


      gcc <filename> -lvpl -lvplmemory -lstdc++


-  On Windows:


   ::


      cl <filename> /link vpl.lib /link vplmemory.lib


DecodeFrame accepts any amount of data from one byte up to the size of a
large internal buffer and return a single frame if one can be decoded.


The important states for normal operation are:


.. container:: tablenoborder


   .. list-table:: 
      :header-rows: 1

      * -     State     
        -     Description     
      * -     \ ``VPL_STATE_READY_FOR_INPUT``\     
        -     Data provided will be read (input will be ignored in    other states).    
      * -     \ ``VPL_STATE_ERROR``\     
        -     An error has occurred.     
      * -     \ ``VPL_STATE_INPUT_BUFFER_FULL``\     
        -     There is no room to read more input, recommendation is to    read out frames before writing more.    
      * -     \ ``VPL_STATE_END_OF_OPERATION``\     
        -     Indicates all available frames have been output (End of    input was reached while the End Of Stream parameter was true.)      



