eDidaktikum
===========

eDidaktikum main module.

Agreements
----------

* We use prefix **ed_** wherever possible (e.g. module names, content type names, database table names).
* We use **node** subtypes for our custom content types as a rule of thumb (if it proves to be problematic, custom entities can be used instead).
* Any submodule should belong to package **eDidaktikum** in order for all related modules to be located in the same place.
* Submodules should generally add **edidaktikum** to dependencies unless there is a good reason not to.
* When adding items to menus that might also be populated by other modules a weight increment of 5 should be used (if that is possible). This way there will be room for additional items to be added in future, if that is needed.

Additional modules used 
-----------------------

Themes used
-----------

* **tweme** located at http://drupal.org/project/tweme

