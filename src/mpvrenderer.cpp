#include <stdexcept>

#include <QOpenGLFramebufferObject>

#include "mpvrenderer.h"

MpvRenderer::MpvRenderer(const MpvObject *obj)
    : mpv(obj->mpv), window(obj->window()), mpv_gl(obj->mpv_gl)
{
    int r = mpv_opengl_cb_init_gl(mpv_gl, nullptr, get_proc_address, nullptr);
    if (r < 0) {
        throw std::runtime_error("OpenGL could not be initialized.");
    }
}

MpvRenderer::~MpvRenderer()
{
    // Until this call is done, we need to make sure the player remains
    // alive. This is done implicitly with the mpv::qt::Handle instance
    // in this class.
    mpv_opengl_cb_uninit_gl(mpv_gl);
}

void MpvRenderer::render()
{
    QOpenGLFramebufferObject* fbo = framebufferObject();
    window->resetOpenGLState();
    mpv_opengl_cb_draw(mpv_gl, fbo->handle(), fbo->width(), fbo->height());
    window->resetOpenGLState();
}
