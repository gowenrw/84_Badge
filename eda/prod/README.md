# Electronic Design Automation / Production PCB(s)

KiCad project folder for the production PCB(s).

## File Structure

This is the file structure of this repository

* [/](/README.md) - Home
* [/eda](/eda/) - Electronic Design Automation files (i.e. KiCad)
  * [/eda/prod/](/eda/prod/) - YOU ARE HERE
    * ./<filename>.pro - project file. Holds parameters that apply to the entire project (e.g. schematic, PCB layout, etc.).
    * ./<filename>.sch - schematic file.
    * ./<filename>.kicad_pcb - the PCB New layout file.
    * ./<filename>.net - netlist in "Pcbnew" format
    * ./<filename>.bak - backup of schematic file.
    * ./<filename>.kicad_pcb-bak - backup of the new PCB layout file.
    * ./<filename>-cache.lib - a local cache copy of all the symbols used in the schematic
    * ./fp-lib-table - Footprint library list
    * ./sym-lib-table - Schematic library list
    * [./3d_models/](/eda/prod/3d_models/) - This directory contains footprint 3d model files
    * [./gerber/](/eda/prod/gerber/) - This directory contains gerber formatted files for manufacturing
    * [./lib_fp/](/eda/prod/lib_fp/) - This directory contains footprint module directories
    * [./lib_sh/](/eda/prod/lib_sh/) - This directory contains schematic library files
    * [./snapshots/](/eda/prod/snapshots/) - This directory contains prints of schematic / cad files and images of preview / final product
