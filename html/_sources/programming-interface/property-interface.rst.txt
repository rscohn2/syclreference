.. _property-interface:

Property Interface
==================


The DPC++ property interface is employed with the ``buffer``, ``image``,
and ``queue`` classes to provide extra information to those classes
without affecting the type. These classes provide an additional
``has_property`` and ``get_property`` member function to test for and
obtain a particular property.

.. include:: property-interface.inc.rst
	     
