/*
 * header.h
 *
 *  Created on: 9 mai 2011
 *      Author: hannibal
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void creerListeNeon();
void creerListeEcran();
void creerListeEcranBack();
void creerListeEcran2();
void creerListeEcran3();
void creerListeEcran4();
void creerListeEcranPlace();
void creerListeTour();
void creerListeTourPlace();
void creerListeClavier();
void creerListeClavierPlace();
void creerListeChaise();
void creerListeChaisePlace();
void creerListePorte();
void creerListeTableau();
void creerListeSalle();
void creerListeTable();
void creerListeFeuille();
void creerListeArbre();

void afficheArbre();
void afficheEcran();
void afficheTour();
void afficheClavier();
void afficheChaise();
void afficheTable();

void afficher();
void rafraichir(int width, int height);
void calculObs();
int angleAleat(int a, int b);
void keyboard(unsigned char key, int x, int y);
void special(int key, int x, int y);
void motion(int x, int y);
void positionLumiere();
void initialiserLumiere();
void initialiserTexture();
void afficheExterieur();
void creerCube(GLuint id1, GLuint id2, GLuint id3, GLuint id4, GLuint id5, GLuint id6,int salle);


typedef struct
{
  GLsizei width;
  GLsizei height;

  GLenum format;
  GLint	internalFormat;
  GLuint id;

  GLubyte *texels;

} gl_texture_t;



//void GetTextureInfo (tga_header_t *header, gl_texture_t *texinfo);
void ReadTGA8bits (FILE *fp, GLubyte *colormap, gl_texture_t *texinfo);
void ReadTGA16bits (FILE *fp, gl_texture_t *texinfo);
void ReadTGA24bits (FILE *fp, gl_texture_t *texinfo);
void ReadTGA32bits (FILE *fp, gl_texture_t *texinfo);
void ReadTGAgray8bits (FILE *fp, gl_texture_t *texinfo);
void ReadTGAgray16bits (FILE *fp, gl_texture_t *texinfo);
void ReadTGA8bitsRLE (FILE *fp, GLubyte *colormap, gl_texture_t *texinfo);
void ReadTGA16bitsRLE (FILE *fp, gl_texture_t *texinfo);
void ReadTGA24bitsRLE (FILE *fp, gl_texture_t *texinfo);
void ReadTGA32bitsRLE (FILE *fp, gl_texture_t *texinfo);
void ReadTGAgray8bitsRLE (FILE *fp, gl_texture_t *texinfo);
void ReadTGAgray16bitsRLE (FILE *fp, gl_texture_t *texinfo);
gl_texture_t * ReadTGAFile (const char *filename);

#endif /* HEADER_H_ */
