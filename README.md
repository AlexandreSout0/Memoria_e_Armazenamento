# Memoria_e_Armazenamento

Flash Memory acess with NVS

int32_t acessVal_NVS();
void writeVal_NVS(int32_t valor);


## PlatformIO: Upload Files to Filesystem (SPIFFS)

Create a folder called data inside your project folder. This can be done on VS Code.
With your mouse, select the project folder you’re working on. Click on the New Folder icon to create a new folder.

This new folder must be called data, otherwise, it won’t work.

Uploading Filesystem Image
After creating and saving the file or files you want to upload under the data folder, follow the next steps:

- 1 - Click the PIO icon at the left side bar. The project tasks should open.
- 2 - Select env:esp32doit-devkit-v1 (it may be slightly different depending on the board you’re using).
- 3 - Expand the Platform menu.
- 4 - Select Build Filesystem Image.
- 5 - Finally, click Upload Filesystem Image.


 ![Upload-filesystem-image-ESP32-VS-Code-PlatformIO-SPIFFS](https://user-images.githubusercontent.com/17073678/205986554-abbbd7a1-2a69-44cd-a1ae-efa44411f788.jpg)




