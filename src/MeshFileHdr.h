#ifndef MESH_FILE_HDR_H
#define MESH_FILE_HDR_H


namespace Azul
{
	struct MeshFileHdr
	{
	public:
		static const unsigned int OBJECT_NAME_SIZE = 32;
		static const unsigned int TEXTURE_NAME_SIZE = 32;

	public:
		MeshFileHdr();
		MeshFileHdr(const MeshFileHdr&) = delete;
		MeshFileHdr& operator = (const MeshFileHdr&) = delete;
		~MeshFileHdr() = default;

	public:
		// Data -----------------

		// object name
		char	objName[OBJECT_NAME_SIZE];

		// vertex buffer
		int		numVerts;
		DWORD	vertBufferOffset;

		// trilist index 
		int		numTriList;
		DWORD	triListBufferOffset;

	};


}

#endif
