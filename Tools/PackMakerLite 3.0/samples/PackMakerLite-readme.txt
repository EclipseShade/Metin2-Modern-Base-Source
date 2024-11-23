Run install.bat as admin OR copy the following files in "c:\windows\system32\":
 PackMakerLite.exe
 PackMakerLite_p.bat
 PackMakerLite_u.bat

To get menu integration, run:
 PML_Pack.add.reg
 PML_Unpack.add.reg

--------------------------------------
If you want to customize the tool,
 copy and edit PackMakerLite.json in the relative working directly
 (where the .eix files are present)
 (PackMakerLite.json.sample contains a sample of any customizable field)

If you want to customize only a specific pack (e.g. ETC),
 just rename it as <packname>.json (e.g. etc.json)

Since v2.3, you can globally load the json files from %userprofile%
 as well if the local ones are missing.
 (%userprofile% = C:\Users\<username>)

Since v2.6, the packer loads "cshybridcrypt_<packname>.dat" with --load_cs <packname> to unpack type 4-5.
 i.e. it must be used before -u/--unpack, not after

Since v2.7, --load_cs and --create_cs can be omitted with --typeforce


tl;dr if you try to pack root, it will search the settings in the following order:
 'root.json' (<packname>.json)
 'PackMakerLite.json'
 'C:\Users\Marty\root.json' (%userprofile%/<packname>.json)
 'C:\Users\Marty\PackMakerLite.json' (%userprofile%/PackMakerLite.json)
