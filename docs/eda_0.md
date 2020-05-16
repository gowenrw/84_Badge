---
title: EDA
has_children: true
nav_order: 4
---

# The EDA work on the 84 Badge

This is where I will review the Electronic Design Automation work done to produce the PCB(s) for the badge and its development board.

## KiCad

I used [KiCad 5.1](https://kicad-pcb.org/) as my EDA program for this badge.

I configure my KiCad projects to use local libraries for long term sustainability per the best practices listed [HERE](https://hackaday.com/2017/05/18/kicad-best-practises-library-management/) and elsewhere.

Beyond the fact that I use some components that are not in the default KiCad libraries, copying the default components I use into my local project libraries ensures that if KiCad makes changes in the future, my projects will retain the original versions of these components keeping them compatible.

What this means for you is that when you download my project and open it up in KiCad you will have all the same exact component schematic and footprint files available to you that I did when I created the project.
