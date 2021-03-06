/* @@@LICENSE
*
*      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */




#ifndef REMOTEWINDOWDATAOPENGL_H
#define REMOTEWINDOWDATAOPENGL_H

#include "Common.h"

#include "RemoteWindowData.h"

class PGSurface;
class PGContext;
class PIpcBuffer;

class RemoteWindowDataOpenGL : public RemoteWindowData
{
public:

	RemoteWindowDataOpenGL(int width, int height, bool hasAlpha, bool createIpcBuffer=true);
	virtual ~RemoteWindowDataOpenGL();

	virtual int key() const;
	virtual int width() const { return m_width; }
	virtual int height() const { return m_height; }
	virtual bool hasAlpha() const { return m_hasAlpha; }
	virtual bool needsClear() const { return false; }
	virtual bool supportsPartialUpdates() const { return false; }
	virtual void setWindowMetaDataBuffer(PIpcBuffer* metaDataBuffer);
	virtual void flip();

	virtual PGContext* renderingContext();
	virtual void beginPaint();
	virtual void endPaint(bool preserveOnFlip, const PRect& rect, bool flipBuffers = true);
	virtual void sendWindowUpdate(int x, int y, int w, int h);
	
	virtual bool hasDirectRendering() const;
	virtual bool directRenderingAllowed(bool val);

	virtual void prepareSceneTransition(CardWebApp* cardWebApp);
	virtual void prepareCrossAppSceneTransition();
	virtual void runSceneTransition(CardWebApp* cardWebApp, const char* transitionType,
			bool isPop, int appBufWidth, int appBufHeight);
	virtual void crossAppSceneActive(CardWebApp* cardWebApp, int appBufWidth, int appBufHeight);
	virtual void cleanupSceneTransition();

	virtual void resize(int newWidth, int newHeight);
	
private:

	PIpcBuffer* m_ipcBuffer;
	int m_width;
	int m_height;
	bool m_hasAlpha;

	PGContext* m_context;
	PGSurface* m_surface;
	bool m_directRendering;
	bool m_displayOpened;
	
private:

	RemoteWindowDataOpenGL(const RemoteWindowDataOpenGL&);
	RemoteWindowDataOpenGL& operator=(const RemoteWindowDataOpenGL&);
};
	

#endif /* REMOTEWINDOWDATAOPENGL_H */
