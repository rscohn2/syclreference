.. _use-the-static-library:

Use the Static Library
======================


After creating the library, use it when creating the final application.
A `fat
library <glossary.html>`__
is treated differently than a regular library. The
``-foffload-static-lib`` option is used to signify the necessary
behavior.


On Linux: ``dpcpp main.cpp      -foffload-static-lib=libapp.a``


On Windows: ``dpcpp main.cpp -foffload-static-lib=libapp.lib``

