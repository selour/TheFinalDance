#include "stdafx.h"
#include "OpenGLTexture.h"
#include <glad/glad.h>
#include <stb_image.h>
namespace Engine
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		:m_Path(path)
	{
        
        // ����ͼƬ
        int width, height, nrComponents;
        stbi_set_flip_vertically_on_load(1);

        unsigned char* image = stbi_load(path.c_str(), &width, &height, &nrComponents, 0);
        ENGINE_ASSERT(image, "Failed to load image!");

        m_Width = width;
        m_Height = height;


     
        GLenum internalFormat = 0, dataFormat = 0;
        if (nrComponents == 4)
        {
            internalFormat = GL_RGBA8;
            dataFormat = GL_RGBA;
        } 
        else if (nrComponents == 3)
        {
            internalFormat = GL_RGB8;
            dataFormat = GL_RGB;
        }
        else if (nrComponents == 1)
        {
            internalFormat = GL_RED;
        }
            
        ENGINE_ASSERT(internalFormat & dataFormat, "Format not supported!");
      

        //��������
        glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);
        glTextureStorage2D(m_TextureID, 1, internalFormat, m_Width, m_Height);
        //��������
        glTextureParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTextureSubImage2D(m_TextureID, 0, 0, 0, m_Width, m_Height, dataFormat, GL_UNSIGNED_BYTE, image);
       
        // �ͷ�ͼ�����ݿռ�
        stbi_image_free(image);
        
	}
	OpenGLTexture2D::~OpenGLTexture2D()
	{
        glDeleteTextures(1, &m_TextureID); 
	}
	void OpenGLTexture2D::Bind(unsigned slot) const
	{
        glBindTextureUnit(slot, m_TextureID);
	}
}