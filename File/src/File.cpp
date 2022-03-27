#include "File.h"

namespace Azul
{

	bool File::IsHandleValid(File::Handle fh) noexcept
	{
		if (fh == INVALID_HANDLE_VALUE)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	File::Error File::Open(File::Handle& fh, const char* const fileName, File::Mode mode) noexcept
	{
		if(mode == File::Mode::READ)
			fh = CreateFileA(fileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
		else if(mode == File::Mode::WRITE)
			fh = CreateFileA(fileName, GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
		else
			fh = CreateFileA(fileName, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

		if (fh == INVALID_HANDLE_VALUE)
		{
			return File::Error::OPEN_FAIL;
		}
		else
		{
			return File::Error::SUCCESS;
		}
	}

	File::Error File::Close(File::Handle &fh) noexcept
	{
		DWORD p = SetFilePointer(fh, 0, NULL, FILE_BEGIN);
		if (p != (DWORD)INVALID_HANDLE_VALUE)
		{
			bool ferror = CloseHandle(fh);

			if (ferror == false || fh == INVALID_HANDLE_VALUE)
				return File::Error::CLOSE_FAIL;
			else
			{
				fh = INVALID_HANDLE_VALUE;
				return File::Error::SUCCESS;
			}

		}
		else 
			return File::Error::CLOSE_FAIL;

	}

	File::Error File::Write(File::Handle fh, const void* const buffer, const DWORD inSize) noexcept
	{
		DWORD dwWirte;
		bool ferror = WriteFile(fh, buffer, inSize, &dwWirte, NULL);
		if (ferror == false)
			return File::Error::WRITE_FAIL;
		else
			return File::Error::SUCCESS;
	}

	File::Error File::Read(File::Handle fh, void* const buffer, const DWORD inSize) noexcept
	{
		DWORD dwRead;
		bool ferror = ReadFile(fh, buffer, inSize, &dwRead, NULL);
		if (ferror == false)
			return File::Error::READ_FAIL;
		else
			return File::Error::SUCCESS;
	}

	File::Error File::Seek(File::Handle fh, File::Position location, long offset) noexcept
	{
		DWORD p = SetFilePointer(fh, offset, NULL, (DWORD)location);
		if (p == (DWORD)INVALID_HANDLE_VALUE)
		{
			return File::Error::SEEK_FAIL;
		}
		else
		{
			return File::Error::SUCCESS;
		}
	}

	File::Error File::Tell(File::Handle fh, DWORD& offset) noexcept
	{
		DWORD curr = SetFilePointer(fh, 0, NULL, FILE_CURRENT);
		DWORD begin = SetFilePointer(fh, 0, NULL, FILE_BEGIN);
		if (curr == (DWORD)INVALID_HANDLE_VALUE || begin == (DWORD)INVALID_HANDLE_VALUE)
		{
			return File::Error::TELL_FAIL;
		}
		offset = curr - begin;
		SetFilePointer(fh, (LONG)offset, NULL, FILE_CURRENT);
		if (offset == (DWORD)INVALID_HANDLE_VALUE)
		{
			return File::Error::TELL_FAIL;
		}
		else
		{
			return File::Error::SUCCESS;
		}
	}

	File::Error File::Flush(File::Handle fh) noexcept
	{
		bool ferror = FlushFileBuffers(fh);
		if (ferror == false)
			return File::Error::FLUSH_FAIL;
		else
			return File::Error::SUCCESS;
	}

}

// ---  End of File ---------------
