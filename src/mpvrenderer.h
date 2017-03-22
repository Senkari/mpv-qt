#ifndef MPVRENDERER_H
#define MPVRENDERER_H

#include <QOpenGLContext>
#include <QQuickFramebufferObject>
#include <QQuickWindow>

#include "mpv/qthelper.hpp"
#include "mpv/opengl_cb.h"

#include "mpvobject.h"

class MpvRenderer : public QQuickFramebufferObject::Renderer
{
private:
    static void* get_proc_address(void* ctx, const char* name) {
        (void) ctx;
        QOpenGLContext* glctx = QOpenGLContext::currentContext();
        if (!glctx) {
            return nullptr;
        }
        return (void *)glctx->getProcAddress(QByteArray(name));
    }

    mpv::qt::Handle mpv;
    QQuickWindow* window;
    mpv_opengl_cb_context* mpv_gl;

public:
    MpvRenderer(const MpvObject* obj);
    virtual ~MpvRenderer();
    void render() override;
};

#endif // MPVRENDERER_H
