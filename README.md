These are hacked versions of examples found in the excellent Graphics chapter
of the openframeworks book: https://github.com/openframeworks/ofBook/blob/master/chapters/intro_to_graphics/chapter.md

# UPDATE DELL XPS 13 INTEL 620 GRAPHICS DRIVERS

In case the drivers are rolled-back by Windows Update.

After install, the drivers for the `Intel HD Graphics 620` device should read:

- Version: 26.20.100.6890
- Date: 5/17/2019

Driver Source: https://downloadcenter.intel.com/product/96551/Intel-HD-Graphics-620
**NOTE**: You want to download the `zip` not the `exe`. The EXE is blocked by Dell
for upgrade since it's not approved.

To Install:

1) Open Device manager
2) Expand `Display Adapters`
3) Right-Click `Intel HD Graphics 620`.
4) Click `Properties` --> `Update Driver`
5) Select `Browse to folder` and select this root dir.
