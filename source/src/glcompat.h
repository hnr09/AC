#ifdef __EMSCRIPTEN__
#ifndef GLCOMPAT_H
#define GLCOMPAT_H
#include <SDL_opengl.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void ac_glVertex2d(double x, double y) { glVertex2f((float)x, (float)y); }
static inline GLuint ac_glGenLists(GLsizei n) { static GLuint c = 1; GLuint r = c; c += n; return r; }
static inline void ac_glNewList(GLuint l, GLenum m) { (void)l; (void)m; }
static inline void ac_glEndList(void) {}
static inline void ac_glCallList(GLuint l) { (void)l; }
static inline void ac_glDeleteLists(GLuint l, GLsizei r) { (void)l; (void)r; }
static inline void ac_glGetTexImage(GLenum t, GLint l, GLenum f, GLenum ty, void* p) { (void)t; (void)l; (void)f; (void)ty; (void)p; }

#ifdef __cplusplus
}
#endif

#define glVertex2d ac_glVertex2d
#define glGenLists ac_glGenLists
#define glNewList ac_glNewList
#define glEndList ac_glEndList
#define glCallList ac_glCallList
#define glDeleteLists ac_glDeleteLists
#define glGetTexImage ac_glGetTexImage

#endif
#endif
