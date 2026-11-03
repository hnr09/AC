#ifdef __EMSCRIPTEN__
#include <SDL_opengl.h>
#ifdef __cplusplus
extern "C" {
#endif
// glVertex2d -> float 버전으로 대체
static inline void glVertex2d(double x, double y) { glVertex2f((float)x, (float)y); }
// 디스플레이 리스트: 모델 렌더용. 일단 no-op 스텁 (모델이 안 보일 수 있음)
static inline GLuint glGenLists(GLsizei n) { static GLuint c = 1; GLuint r = c; c += n; return r; }
static inline void glNewList(GLuint l, GLenum m) {}
static inline void glEndList(void) {}
static inline void glCallList(GLuint l) {}
static inline void glDeleteLists(GLuint l, GLsizei r) {}
static inline void glGetTexImage(GLenum t, GLint l, GLenum f, GLenum ty, void* p) {}
#ifdef __cplusplus
}
#endif
#endif
