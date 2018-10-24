#pragma once

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "..\\..\\lib\\x64\\glew32.lib") 
#pragma comment(lib, "..\\..\\lib\\x64\\DevIL.lib")
#pragma comment(lib, "..\\..\\lib\\x64\\assimp-vc140-mt.lib")

#include <GL/glew.h>
#include <GL/wglew.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <IL/il.h>

#include <fstream>

//to map image filenames to textureIds
#include <string.h>
#include <map>


// assimp include files. These three are usually needed.
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "assimp/scene.h"
#include "assimp/DefaultLogger.hpp"
#include "assimp/LogStream.hpp"

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"

// OpenGLRenderer

class OpenGLRenderer : public CWnd
{
public:
	OpenGLRenderer();
	virtual ~OpenGLRenderer();
	bool CreateGLContext(CRect rect, CWnd *parent);
	void PrepareScene(int sx, int sy, int cx, int cy);				// Scene preparation
	void DestroyScene();            // Cleanup
	
protected:
	bool InitContext(CWnd *parent);					 // Creates OpenGL Rendering Context
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	HGLRC m_hrc;                        // OpenGL Rendering Context 
	HDC m_hdc;
	CRect m_rect;

	DECLARE_MESSAGE_MAP()


public:
	GLfloat		xrot = 0;
	GLfloat		yrot = 0;
	GLfloat		zrot=0;

	// the global Assimp scene object
	const aiScene* scene = NULL;
	GLuint scene_list = 0;
	aiVector3D scene_min, scene_max, scene_center;

	// images / texture
	std::map<std::string, GLuint*> textureIdMap;	// map image filenames to textureIds
	GLuint*		textureIds;							// pointer to texture Array
	// Create an instance of the Importer class
	Assimp::Importer importer;


public:
	GLboolean abortGLInit(const char*);
	void createAILogger();
	void destroyAILogger();
	void logInfo(std::string logString);
	void logDebug(const char* logString);
	bool Import3DFromFile();

	std::string getBasePath();
	int LoadGLTextures(const aiScene* scene);
	void Color4f(const aiColor4D *color);
	void set_float4(float f[4], float a, float b, float c, float d);
	void color4_to_float4(const aiColor4D *c, float f[4]);
	void apply_material(const aiMaterial *mtl);
	void recursive_render(const struct aiScene *sc, const struct aiNode* nd, float scale);
	void drawAiScene(const aiScene* scene);
	int DrawGLScene();				//Here's where we do all the drawing
	bool initAi();

};
