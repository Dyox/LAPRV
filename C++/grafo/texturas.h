#include <iostream>
#include<GL/glaux.h>
#pragma comment (lib, "glaux.lib")    // alternativa a inserir glaux.lib nas definições do projecto (linker)
#define NUM_TEXTURAS 1
GLuint texs[NUM_TEXTURAS]; // para guardar identificadores de texturas

AUX_RGBImageRec *LoadBMP(char *Filename) // Loads A Bitmap Image
{
  FILE *File=NULL; // File Handle

  if (!Filename) // Make Sure A Filename Was Given  
  {
    return NULL; // If Not Return NULL
  }

  File=fopen(Filename,"r"); // Check To See If The File Exists

  if (File) // Does The File Exist?
  {
    fclose(File); // Close The Handle
    return auxDIBImageLoad(Filename); // Load The Bitmap And Return A Pointer
  }
  return NULL; // If Load Failed Return NULL
}
 

int LoadAllTextures() // Load Bitmaps And Convert To Textures
{
  int Status=FALSE; // Status Indicator

  AUX_RGBImageRec *TextureImage[1]; // Create Storage Space For The Texture
 
  memset(TextureImage,0,sizeof(void *)*1); // Set The Pointer To NULL
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  // Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
  if (TextureImage[0]=LoadBMP("avatar.bmp"))
  {
    Status=TRUE; // Set The Status To TRUE

    // Create MipMapped Texture
    glBindTexture(GL_TEXTURE_2D, texs[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
  }

  if (TextureImage[0]) // If Texture Exists
  {
    if (TextureImage[0]->data) // If Texture Image Exists
    {
       free(TextureImage[0]->data); // Free The Texture Image Memory
    }

    free(TextureImage[0]); // Free The Image Structure 
  }
  if (TextureImage[0]=LoadBMP("coca_cola.bmp"))
  {
    Status=TRUE; // Set The Status To TRUE

    // Create MipMapped Texture 
    glBindTexture(GL_TEXTURE_2D, texs[1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
  }

  if (TextureImage[0]) // If Texture Exists 
  {
    if (TextureImage[0]->data) // If Texture Image Exists
    {
      free(TextureImage[0]->data); // Free The Texture Image Memory
    }

    free(TextureImage[0]); // Free The Image Structure
  }

  if (TextureImage[0]=LoadBMP("can_bottom.bmp"))
  { 
    Status=TRUE; // Set The Status To TRUE

    // Create MipMapped Texture
    glBindTexture(GL_TEXTURE_2D, texs[2]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
  }

  if (TextureImage[0]) // If Texture Exists
  {
    if (TextureImage[0]->data) // If Texture Image Exists
    {
      free(TextureImage[0]->data); // Free The Texture Image Memory
    }

    free(TextureImage[0]); // Free The Image Structure
  }

  glBindTexture(GL_TEXTURE_2D, 0);  // desligar a textura


  return Status; // Return The Status
}