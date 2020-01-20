# Electronic Design Automation / Development PCB(s)

KiCad project folder for initial development PCB(s)

## File Structure

This is the file structure of this repository

* [/](/README.md) - Home
* [/eda](/eda/) - Electronic Design Automation files (i.e. KiCad)
  * [/eda/dev/](/eda/dev/) - YOU ARE HERE
    * ./<filename>.pro - project file. Holds parameters that apply to the entire project (e.g. schematic, PCB layout, etc.).
    * ./<filename>.sch - schematic file.
    * ./<filename>.kicad_pcb - the PCB New layout file.
    * ./<filename>.net - netlist in "Pcbnew" format
    * ./<filename>.bak - backup of schematic file.
    * ./<filename>.kicad_pcb-bak - backup of the new PCB layout file.
    * ./<filename>-cache.lib - a local cache copy of all the symbols used in the schematic
    * ./fp-lib-table - Footprint library list
    * ./sym-lib-table - Schematic library list
    * [./3d_models/](/eda/dev/3d_models/) - This directory contains footprint 3d model files
    * [./gerber/](/eda/dev/gerber/) - This directory contains gerber formatted files for manufacturing
    * [./lib_fp/](/eda/dev/lib_fp/) - This directory contains footprint module directories
    * [./lib_sh/](/eda/dev/lib_sh/) - This directory contains schematic library files
    * [./snapshots/](/eda/dev/snapshots/) - This directory contains prints of schematic / cad files and images of preview / final product
