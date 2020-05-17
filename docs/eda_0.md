---
title: EDA
has_children: true
nav_order: 4
---

# The EDA work on the 84 Badge

This section is where I will review the Electronic Design Automation work done to produce the PCB(s) for the badge and its development board.

On this page I'll review the EDA software I used, the process I follow, and the file layout I used, and the reason I decided on a development board for the project.
On the following pages I will detail the schematic and PCB layouts of the 84 Badge and its development board.

## KiCad

I used [KiCad 5.1](https://kicad-pcb.org/) as my EDA program for this badge.

I configure my KiCad projects to use local libraries for long term sustainability per the best practices listed [HERE](https://hackaday.com/2017/05/18/kicad-best-practises-library-management/) and elsewhere.

Beyond the fact that I use some components that are not in the default KiCad libraries, copying the default components I use into my local project libraries ensures that if KiCad makes changes in the future, my projects will retain the original versions of these components keeping them compatible.

What this means for you is that when you download my project and open it up in KiCad you will have all the same exact component symbol and footprint and 3D model files available to you that I did when I created the project.

## My Process

The process I use when building a PCB in an KiCad is as follows:
* Create the file structure for the project
  * Note: I use a project template github repo to simplify this process as it has all the directories primed with README files.
* Build out the local libraries with any components I know I plan to use. (Others will be added to these libraries as identified)
  * Note: I use a project template github repo to simplify this process that contains most of the generic components I would use built into generic blank KiCad project files.
* Create the electrical schematic and output a netlist
* Create the PCB layout file starting with that netlist
  * This populates the PCB file with all the components from the schematic along with thier associated connection points that will need traces.
* Import the artwork into the silkscreen layers of the PCB
* Arrange the componets on the PCB and lay down the traces and vias
* Generate gerber output files of the PCB
* Send gerber files for manufacturing

## File Layout

This is the file layout I use for any PCB EDA project using KiCad.
Note that I break out development and production boards in thier own directory spaces.
* /eda/ - Electronic Design Automation files (i.e. KiCad)
  * /eda/dev/ - Development PCB
  * or
  * /eda/prod/ - Production PCB
    * ./<filename>.pro - project file. Holds parameters that apply to the entire project (e.g. schematic, PCB layout, etc.).
    * ./<filename>.sch - schematic file.
    * ./<filename>.kicad_pcb - the PCB New layout file.
    * ./<filename>.net - netlist in "Pcbnew" format
    * ./<filename>.bak - backup of schematic file.
    * ./<filename>.kicad_pcb-bak - backup of the new PCB layout file.
    * ./<filename>-cache.lib - a local cache copy of all the symbols used in the schematic
    * ./fp-lib-table - Footprint library list
    * ./sym-lib-table - Schematic library list
    * ./3d_models/ - This directory contains footprint 3d model files
    * ./gerber/ - This directory contains gerber formatted files for manufacturing
    * ./lib_fp/ - This directory contains footprint module directories
    * ./lib_sh/ - This directory contains schematic symbol library files
    * ./snapshots/ - This directory contains prints of schematic / cad files and images of preview / final product

## Development Board

I had an idea of how I wanted the electronics of the badge to be designed, but I needed to test it for several reasons.

This would be only my second time designing a board with the CH552G chip and this would triple the number of LEDs I had previously used.

In addition, I've never used components as small as the SMD 0603 before and had doubt's that I could place the parts by hand (Oh how I wish I could afford a pick and place machine).

The problem was that I was weeks away from having the artwork ready and needed to test my ideas sooner in case it didn't work and needed to be redesigned which might impact the artwork.

So rather than waiting for all the artwork to be done to do a prototype of the full badge I decided to make a development board that would have the same electronics but on a smaller scale without artwork.

It turns out that my electronics design was solid and I was able to place those tiny parts without too much trouble.
So, I just carried this forward to the badge design without change.

This means both the development board and the badge share the same electronics schematic and can use the same code.

This turned out to be an advantage as while I was waiting on the badge prototypes to arrive I was writing code and testing it using the development board.
