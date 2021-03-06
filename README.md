eDidaktikum
===========

eDidaktikum modules directory

Agreements
----------

* All development happens in the **master** branch, once release is ready the code is merged into **production** and that is used as the source for tagging releases and knowing the current state of the codebase.
* eDidaktikum.ee server uses **production** branch as a codebase. All the changes have to be merged into **production** before running update on the server.
* We use prefix **ed_** wherever possible (e.g. module names, content type names, database table names).
* We use **node** subtypes for our custom content types as a rule of thumb (if it proves to be problematic, custom entities can be used instead).
* Any submodule should belong to package **eDidaktikum** in order for all related modules to be located in the same place.
* Submodules should generally add **edidaktikum** to dependencies unless there is a good reason not to.
* When adding items to menus that might also be populated by other modules a weight increment of 5 should be used (if that is possible). This way there will be room for additional items to be added in future, if that is needed.

Theme
-----------

* See [centre-for-educational-technology/edidaktikum_theme](https://github.com/centre-for-educational-technology/edidaktikum_theme)

Wysiwyg
-------

There seem to be many ways of adding a visual editor, but this seemed to be popular and useful enough (allows usage of multiple editors, one at a time).

1. Download the Wysiwyg module from: http://drupal.org/project/wysiwyg. Enable that using **Modules** menu at admin/modules.
3. Click the **Configure** link that will take to admin/config/content/wysiwyg
    - Follow the **INSTALLATION INSTRUCTIONS** to get any editors
        * Please note that sites/all/library directory might not exist yet and has to be created
    - Once installed, choose the appropriate editor to be used for certain text format.
        * Please note that editor configuration for any format is different.

