.. _range:

Range
=====


The DPC++ ``range`` class encapsulates the iteration domain of a
work-group or the entire kernel dispatch. Constructors for a range
object take one, two, or three arguments of ``size_t`` dependent on the
dimensionality of the range, either one, two, or three dimensions
respectively.


Member functions include:


-  ``get`` – obtain the specified dimension
-  ``size`` – obtain the size of the range


Additional functions allow construction of new ranges from old ranges
with additional operations on the range. For example:


::


   Range<2> +() const??

.. include:: range.inc.rst

