#include "header.h"


//angle de la vue
double beta=0;
double alpha=0.2;

//distance de la camera au point vise
double distance_du_point_vise=100;

//Position de la souris au dernier recalcul
double x_pos_souris=0;
double y_pos_souris=0;

//Position de la vue
double x_obs=605.0/2.0;
double y_obs=175.0;
double z_obs=976.0/2.0 +100;

double x_vise=605.0/2.0;
double y_vise=275.0/2.0;
double z_vise=976.0/2.0;

double x_ass=0.0;
double y_ass=1.0;
double z_ass=0.0;

double teta=0.0;

GLuint feuille,arbre,table, salle,chaise,clavier,tour,porte,tableau,ecran,ecranBack,ecran2,neon,ecran3,ecran4, chaisePlace,clavierPlace,tourPlace,ecranPlace;


//id des textures :
GLuint texture_ecran,texture_arbre,texture_herbe,texture_ciel,texture_mur_distant,texture_fenetre,texture_tableau,texture_porte, texture_mur,texture_neon, texture_dalleEcran,texture_dalleEcranBack,texture_dalleEcran2,texture_dalleEcran3,texture_dalleEcran4, texture_tour_ar, texture_chaise, texture_table, texture_sol, texture_clavier, texture_plafond, texture_tour, texture_plastique_noir,texture_peinture_noir,texture_peinture_jaune;

/**
 * Dimension des element d'une table
 */
//les pied
float largeurPied=5.;
float hauteurPied=70.0;
float longueurPied=5.0;
//le plateau
float largeurPlateau=80.;
float hauteurPlateau=2.;
float longueurPlateau=160.;

/**
 * Dimension de la salle
 */
float longueurSalle=976.0;
float hauteurSalle=275.0;
float largeurSalle=605.0;

/**
 * Dimension de la chaise
 */

//les pieds
float largeurPiedChaise=5.;
float hauteurPiedChaise=50.0;
float longueurPiedChaise=5.0;

//le dossier
float largeurDossierChaise=2.;
float hauteurDossierChaise=50.;
float longueurDossierChaise=50.;

//le plateau
float longueurPlateauChaise=50.0;
float hauteurPlateauChaise=2.0;
float largeurPlateauChaise=50.0;


/**
 * Dimension Clavier
 */
float longueurClavier=49.5;
float hauteurClavier=2.0;
float largeurClavier=22.5;


/**
 * Dimension Tour
 */
float longueurTour=50.;
float hauteurTour=60.;
float largeurTour=25.;

/**
 * Dimension Ecran
 */

// base ecran
float longueurBaseEcran=20.;
float hauteurBaseEcran=2.;
float largeurBaseEcran=35.;

// pied ecran
float longueurPiedEcran=3.;
float hauteurPiedEcran=7.5;
float largeurPiedEcran=15.;

// dalle ecran
float longueurDalleEcran=3.;
float hauteurDalleEcran=30.;
float largeurDalleEcran=45.;

// tableau
float largeurTableau=400;
float hauteurTableau=150;
float longueurTableau=1;

// porte
float largeurPorte=85;
float hauteurPorte=200;
float longeurPorte=1;

// neon
float largeurNeon=60;
float hauteurNeon=0.25;
float longeurNeon=125;

/**************** FONCTION DE CREATION DE LISTE *********************/

/**
 * Fonction qui permet de créer la liste d'un neon
 */
void creerListeNeon(){
	neon=glGenLists(1);
	glNewList(neon, GL_COMPILE);
		glColor3f(1,0,0);
		glScalef(largeurNeon, hauteurNeon, longeurNeon);
		creerCube(texture_neon, texture_neon, texture_neon, texture_neon, texture_neon,texture_neon,0);
	glEndList();

}

/**
 * Fonction qui permet de créer la liste de l'ecran
 */
void creerListeEcran(){
	ecran=glGenLists(1);
	glNewList(ecran, GL_COMPILE);
		glColor3f(0.5,0.5,0);
		glTranslatef(0.0, hauteurPied+hauteurPlateau+hauteurBaseEcran/2., 0.0);
		// base ecran
		glPushMatrix();
			glScalef(largeurBaseEcran, hauteurBaseEcran, longueurBaseEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// pied ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran/2., -longueurBaseEcran/2.+longueurPiedEcran/2.+5);
			glScalef(largeurPiedEcran, hauteurPiedEcran, longueurPiedEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// dalle ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran+hauteurDalleEcran/2.,-longueurBaseEcran/2.+longueurDalleEcran/2.+5);
			glScalef(largeurDalleEcran, hauteurDalleEcran, longueurDalleEcran);
			creerCube(texture_plastique_noir, texture_dalleEcran, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();
	glEndList();
}


/**
 * Fonction qui permet de créer la liste de l'ecran
 * (screen backtrack 5 )
 */
void creerListeEcranBack(){
	ecranBack=glGenLists(1);
	glNewList(ecranBack, GL_COMPILE);
		glColor3f(0.5,0.5,0);
		glTranslatef(0.0, hauteurPied+hauteurPlateau+hauteurBaseEcran/2., 0.0);
		// base ecran
		glPushMatrix();
			glScalef(largeurBaseEcran, hauteurBaseEcran, longueurBaseEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// pied ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran/2., -longueurBaseEcran/2.+longueurPiedEcran/2.+5);
			glScalef(largeurPiedEcran, hauteurPiedEcran, longueurPiedEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// dalle ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran+hauteurDalleEcran/2.,-longueurBaseEcran/2.+longueurDalleEcran/2.+5);
			glScalef(largeurDalleEcran, hauteurDalleEcran, longueurDalleEcran);
			creerCube(texture_plastique_noir, texture_dalleEcranBack, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();
	glEndList();
}

/**
 * Fonction qui permet de créer la liste de l'ecran
 * (V2)
 */
void creerListeEcran2(){
	ecran2=glGenLists(1);
	glNewList(ecran2, GL_COMPILE);
		glColor3f(0.5,0.5,0);
		glTranslatef(0.0, hauteurPied+hauteurPlateau+hauteurBaseEcran/2., 0.0);
		// base ecran
		glPushMatrix();
			glScalef(largeurBaseEcran, hauteurBaseEcran, longueurBaseEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// pied ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran/2., -longueurBaseEcran/2.+longueurPiedEcran/2.+5);
			glScalef(largeurPiedEcran, hauteurPiedEcran, longueurPiedEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// dalle ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran+hauteurDalleEcran/2.,-longueurBaseEcran/2.+longueurDalleEcran/2.+5);
			glScalef(largeurDalleEcran, hauteurDalleEcran, longueurDalleEcran);
			creerCube(texture_plastique_noir, texture_dalleEcran2, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();
	glEndList();
}
/**
 * Fonction qui permet de créer la liste de l'ecran
 * (V3)
 */
void creerListeEcran3(){
	ecran3=glGenLists(1);
	glNewList(ecran3, GL_COMPILE);
		glColor3f(0.5,0.5,0);
		glTranslatef(0.0, hauteurPied+hauteurPlateau+hauteurBaseEcran/2., 0.0);
		// base ecran
		glPushMatrix();
			glScalef(largeurBaseEcran, hauteurBaseEcran, longueurBaseEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// pied ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran/2., -longueurBaseEcran/2.+longueurPiedEcran/2.+5);
			glScalef(largeurPiedEcran, hauteurPiedEcran, longueurPiedEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// dalle ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran+hauteurDalleEcran/2.,-longueurBaseEcran/2.+longueurDalleEcran/2.+5);
			glScalef(largeurDalleEcran, hauteurDalleEcran, longueurDalleEcran);
			creerCube(texture_plastique_noir, texture_dalleEcran3, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();
	glEndList();
}

/**
 * Fonction qui permet de créer la liste de l'ecran
 * (V4)
 */
void creerListeEcran4(){
	ecran4=glGenLists(1);
	glNewList(ecran4, GL_COMPILE);
		glColor3f(0.5,0.5,0);
		glTranslatef(0.0, hauteurPied+hauteurPlateau+hauteurBaseEcran/2., 0.0);
		// base ecran
		glPushMatrix();
			glScalef(largeurBaseEcran, hauteurBaseEcran, longueurBaseEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// pied ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran/2., -longueurBaseEcran/2.+longueurPiedEcran/2.+5);
			glScalef(largeurPiedEcran, hauteurPiedEcran, longueurPiedEcran);
			creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();

		// dalle ecran
		glPushMatrix();
			glTranslatef(0, hauteurBaseEcran/2.+hauteurPiedEcran+hauteurDalleEcran/2.,-longueurBaseEcran/2.+longueurDalleEcran/2.+5);
			glScalef(largeurDalleEcran, hauteurDalleEcran, longueurDalleEcran);
			creerCube(texture_plastique_noir, texture_dalleEcran4, texture_plastique_noir, texture_plastique_noir,texture_plastique_noir, texture_plastique_noir,0);
		glPopMatrix();
	glEndList();
}


/**
 * Fonction qui permet de creer une liste de tous les ecrans
 * placé dans la salle
 */
void creerListeEcranPlace(){

	// tableau qui va contenir les differents ecran
	GLuint tabEcran []={ecran,ecran2,ecran3,ecran4};

	ecranPlace=glGenLists(1);
	glNewList(ecranPlace, GL_COMPILE);

	//premiere rangé
	glPushMatrix();
		glPushMatrix();
			glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/2., 0.0, 200.0+15);
			glRotatef(angleAleat(-15,15),0,1,0);
			glCallList(tabEcran[angleAleat(0,4)]);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2., 0.0, 200.0+15);
			glRotatef(angleAleat(-15,15),0,1,0);
			glCallList(tabEcran[angleAleat(0,4)]);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/2., 0.0, 200.0+15);
			glRotatef(angleAleat(-15,15),0,1,0);
			glCallList(tabEcran[angleAleat(0,4)]);
		glPopMatrix();
	glPopMatrix();

	int i;
	for(i=1;i<4;i++){

		glPushMatrix();
			glTranslatef(0.0, 0.0, 200.0+(float)(i)*90.0+(float)(i)*largeurPlateau);
			glPushMatrix();
				glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/2., 0.0, 15);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(tabEcran[angleAleat(0,4)]);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2., 0.0, 15);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(tabEcran[angleAleat(0,4)]);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/2., 0.0, 15);
				glRotatef(angleAleat(-15,15),0,1,0);
				if(i==2)
					glCallList(ecranBack);
				else
					glCallList(tabEcran[angleAleat(0,4)]);
			glPopMatrix();
		glPopMatrix();

	}
	glEndList();
}

/**
 * Fonction qui permet de créer la liste de la tour
 */
void creerListeTour(){
	tour=glGenLists(1);
	glNewList(tour, GL_COMPILE);
		glColor3f(0.5,0,0.5);
		glTranslatef(0.0, hauteurPied+hauteurPlateau+hauteurTour/2., 0.0);
		glScalef(largeurTour, hauteurTour, longueurTour);
		creerCube(texture_tour_ar, texture_tour,texture_plastique_noir, texture_plastique_noir,texture_plastique_noir,texture_plastique_noir,0);
		//glutWireCube(1);
	glEndList();
}

/**
 * Fonction qui permet de creer une liste de toutes les tours
 * placé dans la salle
 */
void creerListeTourPlace(){
	tourPlace=glGenLists(1);
	glNewList(tourPlace, GL_COMPILE);

	//premiere rangé
	glPushMatrix();
		glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/1.2, 0.0, 200.0+35);
		glRotatef(angleAleat(-15,15),0,1,0);
		glCallList(tour);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/1.2, 0.0, 200.0+35);
		glRotatef(angleAleat(-15,15),0,1,0);
		glCallList(tour);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/1.2, 0.0, 200.0+35);
		glRotatef(angleAleat(-15,15),0,1,0);
		glCallList(tour);
	glPopMatrix();


	int i;
	for(i=1;i<4;i++){

		glPushMatrix();
			glTranslatef(0.0, 0.0, 200.0+(float)(i)*90.0+(float)(i)*largeurPlateau);
			glPushMatrix();
				glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/1.2, 0.0, 35);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(tour);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/1.2, 0.0, 35);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(tour);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/1.2, 0.0, 35);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(tour);
			glPopMatrix();
		glPopMatrix();

	}

	glEndList();
}

/**
 * Fonction qui permet de créer la liste du clavier
 */
void creerListeClavier(){
	clavier=glGenLists(1);
	glNewList(clavier, GL_COMPILE);
		glColor3f(1,0,0);
		glTranslatef(0.0, hauteurPied+hauteurPlateau+hauteurClavier/2., 0.0);
		glRotatef(90,0,1,0);
		glScalef(largeurClavier, hauteurClavier, longueurClavier);
		creerCube(texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_plastique_noir, texture_clavier,texture_plastique_noir,0);
	glEndList();

}

/**
 * Fonction qui permet de creer une liste de tous les claviers
 * placé dans la salle
 */
void creerListeClavierPlace(){
	clavierPlace=glGenLists(1);
	glNewList(clavierPlace, GL_COMPILE);
	//premiere rangé
	glPushMatrix();
		glPushMatrix();
			glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/2.0, 0.0, 200.0+largeurPlateau-largeurClavier);
			glRotatef(angleAleat(-15,15),0,1,0);
			glCallList(clavier);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2.0, 0.0, 200.0+largeurPlateau-largeurClavier);
			glRotatef(angleAleat(-15,15),0,1,0);
			glCallList(clavier);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/2.0, 0.0, 200.0+largeurPlateau-largeurClavier);
			glRotatef(angleAleat(-15,15),0,1,0);
			glCallList(clavier);
		glPopMatrix();
	glPopMatrix();


	int i;
	for(i=1;i<4;i++){

		glPushMatrix();
			glTranslatef(0.0, 0.0, 200.0+(float)(i)*90.0+(float)(i)*largeurPlateau);
			glPushMatrix();
				glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0+largeurClavier-10);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(clavier);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0+largeurClavier-10);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(clavier);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0+largeurClavier-10);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(clavier);
			glPopMatrix();
		glPopMatrix();

	}
	glEndList();
}


/**
 * Fonction qui permet de créer la liste de la chaise
 */
void creerListeChaise(){
	chaise=glGenLists(1);
	glNewList(chaise, GL_COMPILE);
		glColor3f(0,1,0);
		//le plateau de la chaise
		glPushMatrix();
			glTranslatef(0.0, hauteurPiedChaise+hauteurPlateauChaise/2.0, 0.0);
			glScalef(largeurPlateauChaise, hauteurPlateauChaise, longueurPlateauChaise);
			creerCube(texture_chaise, texture_chaise, texture_chaise,texture_chaise, texture_chaise, texture_chaise,0);
		glPopMatrix();

		//***********les pieds de la chaise

		//le pied a gauche au fond
		glPushMatrix();
			glTranslatef(3+longueurPiedChaise/2.0-longueurPlateauChaise/2., hauteurPiedChaise/2.0, 3+largeurPiedChaise/2.0-largeurPlateauChaise/2.0);
			glScalef(longueurPiedChaise, hauteurPiedChaise, largeurPiedChaise);
			creerCube(texture_peinture_jaune, texture_peinture_jaune, texture_peinture_jaune,texture_peinture_jaune, texture_peinture_jaune, texture_peinture_jaune,0);
		glPopMatrix();

		//le pied a droite au fond
		glPushMatrix();
			glTranslatef(-3-longueurPiedChaise/2.0+longueurPlateauChaise/2., hauteurPiedChaise/2.0, 3+largeurPiedChaise/2.0-largeurPlateauChaise/2.0);
			glScalef(longueurPiedChaise, hauteurPiedChaise, largeurPiedChaise);
			creerCube(texture_peinture_jaune, texture_peinture_jaune, texture_peinture_jaune,texture_peinture_jaune, texture_peinture_jaune, texture_peinture_jaune,0);
		glPopMatrix();

		//le pied a gauche devant
		glPushMatrix();
			glTranslatef(3+longueurPiedChaise/2.0-longueurPlateauChaise/2., hauteurPiedChaise/2.0, -3-largeurPiedChaise/2.0+largeurPlateauChaise/2.0);
			glScalef(longueurPiedChaise, hauteurPiedChaise, largeurPiedChaise);
			creerCube(texture_peinture_jaune, texture_peinture_jaune, texture_peinture_jaune,texture_peinture_jaune, texture_peinture_jaune, texture_peinture_jaune,0);
		glPopMatrix();

		//le pied a droite devant
		glPushMatrix();
			glTranslatef(-3-longueurPiedChaise/2.0+longueurPlateauChaise/2., hauteurPiedChaise/2.0, -3-largeurPiedChaise/2.0+largeurPlateauChaise/2.0);
			glScalef(longueurPiedChaise, hauteurPiedChaise, largeurPiedChaise);
			creerCube(texture_peinture_jaune, texture_peinture_jaune, texture_peinture_jaune,texture_peinture_jaune, texture_peinture_jaune, texture_peinture_jaune,0);
		glPopMatrix();

		//dossier de la chaise
		glPushMatrix();
			glTranslatef(0.,hauteurDossierChaise+hauteurPiedChaise/2,largeurDossierChaise/2.+largeurPlateauChaise/2.+largeurDossierChaise);
			glRotatef(10.,1,0,0);
			glScalef(longueurDossierChaise, hauteurDossierChaise, largeurDossierChaise);
			creerCube(texture_chaise, texture_chaise, texture_chaise,texture_chaise, texture_chaise, texture_chaise,0);
		glPopMatrix();

	glEndList();
}

/**
 * Fonction qui permet de creer une liste de toutes les chaises
 * placé dans la salle
 */
void creerListeChaisePlace(){
	chaisePlace=glGenLists(1);
	glNewList(chaisePlace, GL_COMPILE);
		//chaise prof
		glPushMatrix();
			glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2.0, 0.0, 200.0-largeurPlateau-5);
			glRotatef(194,0,1,0);
			glCallList(chaise);
		glPopMatrix();

		//chaise premiere rangé
		glPushMatrix();
			glTranslatef(0.0, 0.0, 200.0+largeurPlateau/2.+largeurPlateauChaise/2.);
			glPushMatrix();
				glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/2.0,0.,0.);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(chaise);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2.0,0.,0.);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(chaise);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/2.0,0.,0.);
				glRotatef(angleAleat(-15,15),0,1,0);
				glCallList(chaise);
			glPopMatrix();
		glPopMatrix();

		int i;
		for(i=1;i<4;i++){


			glPushMatrix();
				glTranslatef(0.0, 0.0, 200.0+largeurPlateau+largeurPlateauChaise/2.+(float)(i)*95.0+(float)(i)*(largeurPlateau/2.+largeurPlateauChaise/2.));
				glPushMatrix();

					glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/2.0,0.,0.);
					glRotatef(angleAleat(-15,15),0,1,0);
					glCallList(chaise);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2.0,0.,0.);
					glRotatef(angleAleat(-15,15),0,1,0);
					glCallList(chaise);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/2.0,0.,0.);
					glRotatef(angleAleat(-15,15),0,1,0);
					glCallList(chaise);
				glPopMatrix();
			glPopMatrix();

		}
	glEndList();
}


/**
 * Fonction qui permet de céer la liste de la porte
 */
void creerListePorte(){
	porte=glGenLists(1);
	glNewList(porte, GL_COMPILE);
		glPushMatrix();
			glTranslatef(largeurSalle-1, hauteurPorte/2., longeurPorte+100);
			glRotatef(-90,0,1,0);
			glScalef(largeurPorte, hauteurPorte, longeurPorte);
			creerCube(0, texture_porte, 0, 0, 0, 0,0);
		glPopMatrix();

		glPushMatrix();
				glTranslatef(largeurPorte/2. +10, hauteurPorte/2., 1);
				glScalef(largeurPorte, hauteurPorte, longeurPorte);
				creerCube(0, texture_porte, 0, 0, 0, 0,0);
		glPopMatrix();
	glEndList();
}

/**
 * Fonction qui permet de céer la liste du tableau
 */
void creerListeTableau(){
	tableau=glGenLists(1);
	glNewList(tableau, GL_COMPILE);
		glPushMatrix();
			glTranslatef(largeurSalle/2.0 +50, hauteurTableau/2.+100, longueurTableau/2.0);
			glScalef(largeurTableau, hauteurTableau, longueurTableau);
			creerCube(0, texture_tableau, 0, 0, 0, 0,0);
		glPopMatrix();
	glEndList();

}

/**
 * Fonction qui permet de créer la liste de la salle
 */
void creerListeSalle(){
	salle=glGenLists(1);
	glNewList(salle, GL_COMPILE);
		glPushMatrix();
			glTranslatef(largeurSalle/2.0, hauteurSalle/2.0, longueurSalle/2.0);
			glScalef(largeurSalle, hauteurSalle, longueurSalle);
			creerCube(texture_mur, texture_mur, texture_mur,texture_fenetre, texture_plafond, texture_sol,1);
		glPopMatrix();
	glEndList();
}


/**
 * Fonction qui permet de créer la liste de la table
 */
void creerListeTable(){
	table=glGenLists(1);
	glNewList(table, GL_COMPILE);


		/*float couleurAmb2[]={1,1,1, 1.};
		float couleurDiff2[]={1,1,1, 1.};
		float couleurSpec2[]={1,1,1, 1.};
		float shininess[]={110.};
		glMaterialfv(GL_FRONT, GL_AMBIENT, couleurAmb2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, couleurDiff2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, couleurSpec2);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);*/

		//Le plateau
		glPushMatrix();
			glTranslatef(0.0, hauteurPied+hauteurPlateau/2.0, 0.0);
			glScalef(longueurPlateau, hauteurPlateau, largeurPlateau);
			creerCube(texture_peinture_noir, texture_peinture_noir, texture_peinture_noir, texture_peinture_noir, texture_table, texture_peinture_noir,0);
		glPopMatrix();

		//le pied a gauche au fond
		glPushMatrix();
			glTranslatef(3+longueurPied/2.0-longueurPlateau/2., hauteurPied/2.0, 3+largeurPied/2.0-largeurPlateau/2.0);
			glScalef(longueurPied, hauteurPied, largeurPied);
			creerCube(texture_peinture_noir, texture_peinture_noir, texture_peinture_noir,texture_peinture_noir, texture_peinture_noir, texture_peinture_noir,0);
		glPopMatrix();

		//le pied a droite au fond
		glPushMatrix();
			glTranslatef(-3-longueurPied/2.0+longueurPlateau/2., hauteurPied/2.0, 3+largeurPied/2.0-largeurPlateau/2.0);
			glScalef(longueurPied, hauteurPied, largeurPied);
			creerCube(texture_peinture_noir, texture_peinture_noir, texture_peinture_noir,texture_peinture_noir, texture_peinture_noir, texture_peinture_noir,0);
		glPopMatrix();

		//le pied a gauche devant
		glPushMatrix();
			glTranslatef(3+longueurPied/2.0-longueurPlateau/2., hauteurPied/2.0, -3-largeurPied/2.0+largeurPlateau/2.0);
			glScalef(longueurPied, hauteurPied, largeurPied);
			creerCube(texture_peinture_noir, texture_peinture_noir, texture_peinture_noir,texture_peinture_noir, texture_peinture_noir, texture_peinture_noir,0);
		glPopMatrix();

		//le pied a droite devant
		glPushMatrix();
			glTranslatef(-3-longueurPied/2.0+longueurPlateau/2., hauteurPied/2.0, -3-largeurPied/2.0+largeurPlateau/2.0);
			glScalef(longueurPied, hauteurPied, largeurPied);
			creerCube(texture_peinture_noir, texture_peinture_noir, texture_peinture_noir,texture_peinture_noir, texture_peinture_noir, texture_peinture_noir,0);
		glPopMatrix();

		/*float couleurAmb3[]={0.75,0.75,0.75, 1.};
		float couleurDiff3[]={0.75,0.75,0.75, 1.};
		float couleurSpec3[]={0.75,0.75,0.75, 1.};
		//float shininess2[]={32.};
		glMaterialfv(GL_FRONT, GL_AMBIENT, couleurAmb3);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, couleurDiff3);
		glMaterialfv(GL_FRONT, GL_SPECULAR, couleurSpec3);*/
	glEndList();
}

/**
 * Fonction qui creer la liste d'une
 * "tranche" d'un arbre
 */
void creerListeFeuille(){

	feuille=glGenLists(1);
	glNewList(feuille, GL_COMPILE);

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture_arbre);
		glBegin(GL_QUADS);
			glNormal3f(1, 0, 0);

			glTexCoord2f(0,0);
			glVertex3f(+0.5,-0.5,-0.5);

			glTexCoord2f(1,0);
			glVertex3f(+0.5,-0.5,+0.5);

			glTexCoord2f(1,1);
			glVertex3f(+0.5,+0.5,+0.5);

			glTexCoord2f(0,1);
			glVertex3f(+0.5,+0.5,-0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
	glEndList();
}

/**
 * Fonction qui creer la liste d'un arbre
 */
void creerListeArbre(){
	arbre=glGenLists(1);
	glNewList(arbre, GL_COMPILE);

	glPushMatrix();
			glScalef(200,500,200);
			glCallList(feuille);
	glPopMatrix();

	glPushMatrix();
					glTranslatef(100,0,100);
					glScalef(200,500,200);
					glRotatef(90,0,1,0);
					glCallList(feuille);
	glPopMatrix();

	glEndList();
}

/********************** FONCTION D'AFFICHAGE DES DIFFERENTS OBJETS ***********************/

/**
 * Fonction qui permet de placer et d'afficher les arbres
 */
void afficheArbre(){

	glPushMatrix();
			glTranslatef(-1000,0,-100);
			glCallList(arbre);
	glPopMatrix();

	glPushMatrix();
				glTranslatef(-600,0,400);
				glCallList(arbre);
	glPopMatrix();

	glPushMatrix();
					glTranslatef(-800,0,750);
					glCallList(arbre);
	glPopMatrix();

	glPushMatrix();
				glTranslatef(-400,0,100);
				glCallList(arbre);
	glPopMatrix();

	glPushMatrix();
					glTranslatef(-300,0,900);
					glCallList(arbre);
	glPopMatrix();


}

/**
 * Fonction qui permet d'afficher les ecrans
 * aux bonnes positions dans la salle
 */
void afficheEcran(){
	glPushMatrix();
		glCallList(ecranPlace);
	glPopMatrix();
}


/**
 * Fonction qui permet d'afficher les tours
 * aux bonnes positions dans la salle
 */
void afficheTour(){
	glPushMatrix();
		glCallList(tourPlace);
	glPopMatrix();
}


/**
 * Fonction qui permet d'afficher les claviers
 * aux bonnes positions dans la salle
 */
void afficheClavier(){
	glPushMatrix();
		glCallList(clavierPlace);
	glPopMatrix();
}


/**
 * Fonction qui permet d'afficher les chaises
 * aux bonnes positions dans la salle
 */
void afficheChaise(){
	glPushMatrix();
		glCallList(chaisePlace);
	glPopMatrix();
}


/**
 * Fonction qui permet d'afficher les tables
 * aux bonnes positions dans la salle
 */
void afficheTable(){
	//bureau du prof
	glPushMatrix();
		glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2.0, 0.0, 200.0-largeurPlateau/2.0-5);
		glCallList(table);
	glPopMatrix();

	//premiere range
	glPushMatrix();
		glTranslatef(0.0, 0.0, 200.0);
		glPushMatrix();
			glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0);
			glCallList(table);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0);
			glCallList(table);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0);
			glCallList(table);
		glPopMatrix();
	glPopMatrix();

	//les 3 autres
	int i;
	for(i=1; i<4; i++){
		glPushMatrix();
			glTranslatef(0.0, 0.0, 200.0+(float)(i)*90.0+(float)(i)*largeurPlateau);
			glPushMatrix();
				glTranslatef(largeurSalle-longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0);
				glCallList(table);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(largeurSalle-2*longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0);
				glCallList(table);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(largeurSalle-3*longueurPlateau+longueurPlateau/2.0, 0.0, largeurPlateau/2.0);
				glCallList(table);
			glPopMatrix();
		glPopMatrix();
	}

}

/**
 * Fonction qui permet d'afficher le mur du fond (visible par la fenetre)
 * et ciel et le sol
 */
void afficheExterieur(){

	glPushMatrix();

		//mur du fond
		glPushMatrix();

			glTranslatef(-1500, hauteurSalle, 0);
			glScalef(1, hauteurSalle*4, longueurSalle*10);

			glBindTexture(GL_TEXTURE_2D, texture_mur_distant);
			glBegin(GL_QUADS);
				//glNormal3f(0, 1, 0);
				glNormal3f(1, 0, 0);

				glTexCoord2f(0,0);
				glVertex3f(+0.5,-0.5,-0.5);

				glTexCoord2f(50,0);
				glVertex3f(+0.5,-0.5,+0.5);

				glTexCoord2f(50,1);
				glVertex3f(+0.5,+0.5,+0.5);

				glTexCoord2f(0,1);
				glVertex3f(+0.5,+0.5,-0.5);
			glEnd();
		glPopMatrix();

			// ciel
		glPushMatrix();
			glTranslatef(-1500/2.,hauteurSalle*3 , 0);
			glScalef(2000, 1, longueurSalle*10);
			glBindTexture(GL_TEXTURE_2D, texture_ciel);
			glBegin(GL_QUADS);
				glNormal3f(0, 1, 0);

				glTexCoord2f(1,0);
				glVertex3f(-0.5,+0.5,-0.5);

				glTexCoord2f(1,1);
				glVertex3f(+0.5,+0.5,-0.5);

				glTexCoord2f(0,1);
				glVertex3f(+0.5,+0.5,+0.5);

				glTexCoord2f(0,0);
				glVertex3f(-0.5,+0.5,+0.5);
			glEnd();
		glPopMatrix();

		// sol
		glPushMatrix();
			glTranslatef(-1500/2.,-hauteurSalle , 0);
			glScalef(2000, 1, longueurSalle*10);
			glBindTexture(GL_TEXTURE_2D, texture_herbe);
			glBegin(GL_QUADS);

				glNormal3f(0, -1, 0);

				glTexCoord2f(10,0);
				glVertex3f(-0.5,-0.5,+0.5);

				glTexCoord2f(10,5);
				glVertex3f(+0.5,-0.5,+0.5);

				glTexCoord2f(0,5);
				glVertex3f(+0.5,-0.5,-0.5);

				glTexCoord2f(0,0);
				glVertex3f(-0.5,-0.5,-0.5);
			glEnd();
		glPopMatrix();


		//mur a droite
		glPushMatrix();
			glTranslatef(-600, hauteurSalle, -longueurSalle*5);
			glScalef(1800, hauteurSalle*4, 0);

			glBindTexture(GL_TEXTURE_2D, texture_mur_distant);
			glBegin(GL_QUADS);

				glNormal3f(0, 0, -1);

				glTexCoord2f(0,0);
				glVertex3f(-0.5,-0.5,-0.5);

				glTexCoord2f(10,0);
				glVertex3f(+0.5,-0.5,-0.5);

				glTexCoord2f(10,1);
				glVertex3f(+0.5,+0.5,-0.5);

				glTexCoord2f(0,1);
				glVertex3f(-0.5,+0.5,-0.5);
			glEnd();
		glPopMatrix();

		// mur de gauche
		glPushMatrix();
			glTranslatef(-600, hauteurSalle, longueurSalle*5);
			glScalef(1800, hauteurSalle*4, 0);

			glBindTexture(GL_TEXTURE_2D, texture_mur_distant);
			glBegin(GL_QUADS);

				glNormal3f(0, 0, -1);

				glTexCoord2f(0,0);
				glVertex3f(-0.5,-0.5,-0.5);

				glTexCoord2f(10,0);
				glVertex3f(+0.5,-0.5,-0.5);

				glTexCoord2f(10,1);
				glVertex3f(+0.5,+0.5,-0.5);

				glTexCoord2f(0,1);
				glVertex3f(-0.5,+0.5,-0.5);
			glEnd();
		glPopMatrix();


		glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

}

/************************ AUTRES FONCTIONS *********************/

/**
 * Fonction qui permet de créer un cube de base avec des textures directement
 * appliqué sur chacune des faces.
 * le parametre salle permet de générer des normales dans le sens opposés des normales pour les
 * autre objet
 */
void creerCube(GLuint id1, GLuint id2, GLuint id3, GLuint id4, GLuint id5, GLuint id6,int salle){
	//Premiere face
	glBindTexture(GL_TEXTURE_2D, id1);
	glBegin(GL_QUADS);

		if(salle==0)
			glNormal3f(0, 0, -1);
		else
			glNormal3f(0, 0, 1);

		glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,-0.5);

		glTexCoord2f(1,0);
		glVertex3f(+0.5,-0.5,-0.5);

		glTexCoord2f(1,1);
		glVertex3f(+0.5,+0.5,-0.5);

		glTexCoord2f(0,1);
		glVertex3f(-0.5,+0.5,-0.5);
	glEnd();

	//deuxieme face
	glBindTexture(GL_TEXTURE_2D, id2);
	glBegin(GL_QUADS);

		if(salle==0)
			glNormal3f(0, 0, 1);
		else
			glNormal3f(0, 0, -1);

		glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,+0.5);

		glTexCoord2f(1,0);
		glVertex3f(+0.5,-0.5,+0.5);

		glTexCoord2f(1,1);
		glVertex3f(+0.5,+0.5,+0.5);

		glTexCoord2f(0,1);
		glVertex3f(-0.5,+0.5,+0.5);
	glEnd();

	//troisieme face
	glBindTexture(GL_TEXTURE_2D, id3);
	glBegin(GL_QUADS);

		if(salle==0)
			glNormal3f(1, 0, 0);
		else
			glNormal3f(-1,0,0);

		glTexCoord2f(0,0);
		glVertex3f(+0.5,-0.5,-0.5);

		glTexCoord2f(1,0);
		glVertex3f(+0.5,-0.5,+0.5);

		glTexCoord2f(1,1);
		glVertex3f(+0.5,+0.5,+0.5);

		glTexCoord2f(0,1);
		glVertex3f(+0.5,+0.5,-0.5);
	glEnd();

	//quatrieme face
	glBindTexture(GL_TEXTURE_2D, id4);
	glBegin(GL_QUADS);
		//glNormal3f(0, -1, 0);

		if(salle==0)
			glNormal3f(-1, 0, 0);
		else
			glNormal3f(1,0,0);

		glTexCoord2f(0,0);

		glVertex3f(-0.5,-0.5,-0.5);

		if(salle==1)
			glTexCoord2f(4,0);
		else
			glTexCoord2f(1,0);


		glVertex3f(-0.5,-0.5,+0.5);

		if(salle==1)
			glTexCoord2f(4,1);
		else
			glTexCoord2f(1,1);

		glVertex3f(-0.5,+0.5,+0.5);

		glTexCoord2f(0,1);
		glVertex3f(-0.5,+0.5,-0.5);
	glEnd();

	//cinquieme face
	glBindTexture(GL_TEXTURE_2D, id5);
	glBegin(GL_QUADS);

		if(salle==0)
			glNormal3f(0, 1, 0);
		else
			glNormal3f(0,-1,0);

		if(salle==0)
			glTexCoord2f(1,0);
		else
			glTexCoord2f(10,0);

		glVertex3f(-0.5,+0.5,-0.5);

		if(salle==0)
			glTexCoord2f(1,1);
		else
			glTexCoord2f(10,10);

		glVertex3f(+0.5,+0.5,-0.5);

		if(salle==0)
			glTexCoord2f(0,1);
		else
			glTexCoord2f(0,10);

		glVertex3f(+0.5,+0.5,+0.5);

		glTexCoord2f(0,0);
		glVertex3f(-0.5,+0.5,+0.5);
	glEnd();

	//sixieme face
	glBindTexture(GL_TEXTURE_2D, id6);
	glBegin(GL_QUADS);

		if(salle==0)
			glNormal3f(0, -1, 0);
		else
			glNormal3f(0,1,0);

		glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,+0.5);

		glTexCoord2f(1,1);
		glVertex3f(+0.5,-0.5,+0.5);

		glTexCoord2f(0,1);
		glVertex3f(+0.5,-0.5,-0.5);

		glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,-0.5);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

/**
 * Fonction principale d'affichage
 */
void afficher()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x_obs, y_obs, z_obs,  x_vise, y_vise, z_vise,   x_ass, y_ass, z_ass);

	float couleurAmb2[]={1,1,1, 1.};
	float couleurDiff2[]={1,1,1, 1.};
	float couleurSpec2[]={1,1,1, 1.};
	float shininess[]={110.};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, couleurAmb2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, couleurDiff2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, couleurSpec2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	//place les lumieres
	positionLumiere();

	// affiche l'exterieur de la piece
	afficheExterieur();

	// affiche les arbres
	afficheArbre();

	// la salle
	glPushMatrix();
		glCallList(salle);
	glPopMatrix();

	// le tableau
	glPushMatrix();
			glCallList(tableau);
	glPopMatrix();

	// la porte
	glPushMatrix();
			glCallList(porte);
	glPopMatrix();

	// les tables
	afficheTable();

	// les chaises
	afficheChaise();

	// les claviers
	afficheClavier();

	// les tours
	afficheTour();

	// les ecrans
	afficheEcran();


	// affichage du point visé
	glPushMatrix();
		float couleurAmb5[]={0.,0.,0., 1.};
		float couleurDiff5[]={0.01,0.01,0.01, 1.};
		float couleurSpec5[]={1,1,1, 1.};
		float shininess5[]={110.};
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, couleurAmb5);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, couleurDiff5);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, couleurSpec5);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess5);

		glTranslatef(x_vise, y_vise, z_vise);
		glutSolidSphere(10,30,30);
	glPopMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, couleurAmb2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, couleurDiff2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, couleurSpec2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);


	if(glGetError()!=0)
		printf("erreur\n");
	glutSwapBuffers();
}

/**
 * Fonction qui permet de rafraichir la visualisation
 */
void rafraichir(int width, int height)
{
	/* PROJECTION : définition du volume de vue */

	glViewport( 0,0, width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glFrustum(-5*tan(M_PI/3.0),5*tan(M_PI/3.0),-6.49,6.49,5,1000.0);

	gluPerspective(90.0,(float)(width)/(float)(height), 5.0, 15000.0);
}

/**
 * Fonction qui permet de calculer les coordonnées de vue
 */
void calculObs(){
	x_obs=x_vise+distance_du_point_vise*cos(beta)*cos(alpha);
	y_obs=y_vise+distance_du_point_vise*sin(alpha);
	z_obs=z_vise+distance_du_point_vise*sin(beta)*cos(alpha);
}

/**
 * Fonction qui permet de retourner un entier
 * aléatoire entre les bornes a et b
 */
int angleAleat(int a, int b){
    	return rand()%(b-a) +a;
}

/**
 * Fonction qui permet de deplacer le point visé
 * Touche z et s deplacement sur l'axe x
 * Touche d et q deplacement sur l'axe z
 * Touche r et f deplacement sur l'axe y
 */
void keyboard(unsigned char key, int x, int y){

	switch(key){
		case 'z':
			x_vise+=10;
			break;
		case 's':
			x_vise-=10;
			break;
		case 'd':
			z_vise+=10;
			break;
		case 'q':
			z_vise-=10;
			break;
		case 'r':
			y_vise+=10;
			break;
		case 'f':
			y_vise-=10;
			break;

	}

	calculObs();
	glutPostRedisplay();
}

/**
 * Fonction qui permet de modifier la distance de l'observateur
 * par rapport au point visé
 * Touche fleche haut et fleche bas
 */
void special(int key, int x, int y){
	switch(key){
		case GLUT_KEY_DOWN :
			distance_du_point_vise-=5;
			break;
		case GLUT_KEY_UP :
			distance_du_point_vise+=5;
			break;
	}

	calculObs();
	glutPostRedisplay();
}

/**
 * Fonction qui permet de deplacer l'observateur
 * sur une sphere autour du point visé
 */
void motion(int x, int y){
	beta+=(x-x_pos_souris)*0.01;

	alpha+=(y-y_pos_souris)*0.01;


	x_pos_souris=x;
	y_pos_souris=y;

	calculObs();
	glutPostRedisplay();
}

/**
 * Fonction qui positionne les lumieres
 */
void positionLumiere(){

	/**** NEON ***/

	double hauteurLumiere=hauteurSalle;
	double hauteurPosNeon=hauteurSalle-hauteurNeon-3;

	//premiere rangé
	float pos[]={400, hauteurLumiere, 358, 1.};
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

	glPushMatrix();
		glTranslatef(pos[0], hauteurPosNeon, pos[2]);
		glCallList(neon);
	glPopMatrix();


	float pos1[]={400, hauteurLumiere, 558, 1.};
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);

	glPushMatrix();
		glTranslatef(pos1[0], hauteurPosNeon, pos1[2]);
		glCallList(neon);
	glPopMatrix();

	float pos2[]={400, hauteurLumiere, 758, 1.};
	glLightfv(GL_LIGHT2, GL_POSITION, pos2);

	glPushMatrix();
		glTranslatef(pos2[0], hauteurPosNeon, pos2[2]);
		glCallList(neon);
	glPopMatrix();


	//seconde rangé
	float pos3[]={200, hauteurLumiere, 358, 1.};
	glLightfv(GL_LIGHT3, GL_POSITION, pos3);

	glPushMatrix();
		glTranslatef(pos3[0], hauteurPosNeon, pos3[2]);
		glCallList(neon);
	glPopMatrix();


	float pos4[]={200, hauteurLumiere, 558, 1.};
	glLightfv(GL_LIGHT4, GL_POSITION, pos4);

	glPushMatrix();
		glTranslatef(pos4[0], hauteurPosNeon, pos4[2]);
		glCallList(neon);
	glPopMatrix();

	float pos5[]={200, hauteurLumiere, 758, 1.};
	glLightfv(GL_LIGHT5, GL_POSITION, pos5);

	glPushMatrix();
		glTranslatef(pos5[0], hauteurPosNeon, pos5[2]);
		glCallList(neon);
	glPopMatrix();
}

/**
 * Fonction qui initialise les lumieres (couleur)
 */
void initialiserLumiere(){

	/*** NEON *****/
	float couleurAmb[]={0.2, 0.2, 0.2, 1.};
	float couleurDiff[]={0.5, 0.5, 0.5, 1.};
	float couleurSpec[]={0.5, 0.5, 0.5, 1.};

	double constant=0.1;
	double linear=0.0001;
	double quad=0.0000001;

	glLightfv(GL_LIGHT0, GL_AMBIENT, couleurAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, couleurDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, couleurSpec);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, constant);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linear);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION,quad );


	glLightfv(GL_LIGHT1, GL_AMBIENT, couleurAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, couleurDiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, couleurSpec);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, constant);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, linear);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, quad);


	glLightfv(GL_LIGHT2, GL_AMBIENT, couleurAmb);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, couleurDiff);
	glLightfv(GL_LIGHT2, GL_SPECULAR, couleurSpec);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, constant);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, linear);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, quad);

	glLightfv(GL_LIGHT3, GL_AMBIENT, couleurAmb);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, couleurDiff);
	glLightfv(GL_LIGHT3, GL_SPECULAR, couleurSpec);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, constant);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, linear);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, quad);

	glLightfv(GL_LIGHT4, GL_AMBIENT, couleurAmb);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, couleurDiff);
	glLightfv(GL_LIGHT4, GL_SPECULAR, couleurSpec);
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, constant);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, linear);
	glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, quad);

	glLightfv(GL_LIGHT5, GL_AMBIENT, couleurAmb);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, couleurDiff);
	glLightfv(GL_LIGHT5, GL_SPECULAR, couleurSpec);
	glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, constant);
	glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, linear);
	glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, quad);

}

/**
 * Fonction qui initialise les textures
 */
void initialiserTexture(){
	int level=0;
	int border=0;
	gl_texture_t* texture;

	glGenTextures(1, &texture_table);
	texture=ReadTGAFile("./textures/texture_table.tga");
	glBindTexture(GL_TEXTURE_2D, texture_table);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_dalleEcran);
	texture=ReadTGAFile("./textures/dalleEcran.tga");
	glBindTexture(GL_TEXTURE_2D, texture_dalleEcran);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_dalleEcran2);
	texture=ReadTGAFile("./textures/dalleEcran2.tga");
	glBindTexture(GL_TEXTURE_2D, texture_dalleEcran2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_dalleEcran3);
	texture=ReadTGAFile("./textures/dalleEcran3.tga");
	glBindTexture(GL_TEXTURE_2D, texture_dalleEcran3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_dalleEcran4);
	texture=ReadTGAFile("./textures/dalleEcran4.tga");
	glBindTexture(GL_TEXTURE_2D, texture_dalleEcran4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_dalleEcranBack);
	texture=ReadTGAFile("./textures/dalleEcranBack.tga");
	glBindTexture(GL_TEXTURE_2D, texture_dalleEcranBack);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_sol);
	texture=ReadTGAFile("./textures/texture_sol.tga");
	glBindTexture(GL_TEXTURE_2D, texture_sol);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_clavier);
	texture=ReadTGAFile("./textures/clavier.tga");
	glBindTexture(GL_TEXTURE_2D, texture_clavier);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_chaise);
	texture=ReadTGAFile("./textures/texture_chaise.tga");
	glBindTexture(GL_TEXTURE_2D, texture_chaise);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_plastique_noir);
	texture=ReadTGAFile("./textures/texture_plastique_noir.tga");
	glBindTexture(GL_TEXTURE_2D, texture_plastique_noir);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_mur);
	texture=ReadTGAFile("./textures/texture_mur.tga");
	glBindTexture(GL_TEXTURE_2D, texture_mur);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_tour);
	texture=ReadTGAFile("./textures/texture_tour.tga");
	glBindTexture(GL_TEXTURE_2D, texture_tour);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_tour_ar);
	texture=ReadTGAFile("./textures/texture_tour_ar.tga");
	glBindTexture(GL_TEXTURE_2D, texture_tour_ar);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_plafond);
	texture=ReadTGAFile("./textures/texture_plafond.tga");
	glBindTexture(GL_TEXTURE_2D, texture_plafond);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_tableau);
	texture=ReadTGAFile("./textures/texture_tableau.tga");
	glBindTexture(GL_TEXTURE_2D, texture_tableau);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_peinture_noir);
	texture=ReadTGAFile("./textures/texture_peinture_noir.tga");
	glBindTexture(GL_TEXTURE_2D, texture_peinture_noir);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_peinture_jaune);
	texture=ReadTGAFile("./textures/texture_peinture_jaune.tga");
	glBindTexture(GL_TEXTURE_2D, texture_peinture_jaune);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_porte);
	texture=ReadTGAFile("./textures/texture_porte.tga");
	glBindTexture(GL_TEXTURE_2D, texture_porte);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_neon);
	texture=ReadTGAFile("./textures/texture_neon.tga");
	glBindTexture(GL_TEXTURE_2D, texture_neon);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

	glGenTextures(1, &texture_fenetre);
	texture=ReadTGAFile("./textures/murFenetre.tga");
	glBindTexture(GL_TEXTURE_2D, texture_fenetre);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_mur_distant);
	texture=ReadTGAFile("./textures/texture_mur_fond.tga");
	glBindTexture(GL_TEXTURE_2D, texture_mur_distant);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_ciel);
	texture=ReadTGAFile("./textures/ciel.tga");
	glBindTexture(GL_TEXTURE_2D, texture_ciel);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_herbe);
	texture=ReadTGAFile("./textures/herbe.tga");
	glBindTexture(GL_TEXTURE_2D, texture_herbe);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);


	glGenTextures(1, &texture_arbre);
	texture=ReadTGAFile("./textures/arbre.tga");
	glBindTexture(GL_TEXTURE_2D, texture_arbre);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, level, texture->internalFormat, texture->width, texture->height, border, texture->format, GL_UNSIGNED_BYTE, texture->texels);

}



int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(10,10);
	glutCreateWindow("La salle");

	glEnable(GL_NORMALIZE);
	glEnable(GL_RESCALE_NORMAL);

	/**
	  * gestion de la lumiere
	  */
	initialiserLumiere();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_DEPTH_TEST);


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	/**
	  * gestion des texture
	  */
	initialiserTexture();
	glEnable(GL_TEXTURE_2D);

	// Initialisation des listes
	creerListeNeon();
	creerListePorte();
	creerListeTableau();
	creerListeSalle();
	creerListeTable();
	creerListeChaise();
	creerListeChaisePlace();
	creerListeClavier();
	creerListeClavierPlace();
	creerListeTour();
	creerListeTourPlace();
	creerListeEcran();
	creerListeEcranBack();
	creerListeEcran2();
	creerListeEcran3();
	creerListeEcran4();
	creerListeEcranPlace();
	creerListeFeuille();
	creerListeArbre();

	glutDisplayFunc(&afficher);
	glutReshapeFunc(&rafraichir);
	glutKeyboardFunc(&keyboard);
	glutSpecialFunc(&special);
	glutMotionFunc(&motion);
	//glutPassiveMotionFunc(&pMotion);



	glutMainLoop();

	return 0;
}
