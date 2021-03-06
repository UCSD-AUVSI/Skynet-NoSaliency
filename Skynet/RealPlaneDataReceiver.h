#pragma once
#include "PlaneDataReceiver.h"
#using <System.dll>

namespace Skynet {
	ref class SkynetController;
}

public ref class RealPlaneDataReceiver : PlaneDataReceiver
{
public:
	RealPlaneDataReceiver(Skynet::SkynetController^ skynetController, System::String ^ directory,
				  Communications::PlaneWatcher ^ planeWatcher);
protected:
	virtual void run() override;
private: 
	Skynet::SkynetController^ skynetController;
	void fileAdded(Object^ sender, System::IO::FileSystemEventArgs^ e);
	void fileRenamed(Object^ sender, System::IO::RenamedEventArgs^ e);
	void processFile(System::String^ imageFilename);
};