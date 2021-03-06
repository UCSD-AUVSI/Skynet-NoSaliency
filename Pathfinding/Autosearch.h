/* Autosearch Header File */
#pragma once
#define NOT_SEEN 1

namespace Skynet
{
	ref class SkynetController;
}

namespace Communications
{
	ref class PlaneWatcher;
}

namespace Intelligence {
	ref class IntelligenceController;

	ref struct GPSCoord;
	ref struct ArrayCoord;
	public ref class Autosearch
	{
	public:
		array<int>^ map;
		Autosearch(System::String ^ filename,Intelligence::IntelligenceController^ controller);
		Autosearch(array<System::String^> ^ coords,Intelligence::IntelligenceController^ controller);
		Autosearch(array<Intelligence::GPSCoord ^> ^coords,Intelligence::IntelligenceController^ controller);
		void update(ImageWithPlaneData^ data);
		void Autosearch::markPolygon(array<Intelligence::GPSCoord ^> ^coords, short value);
		System::String^ toString();
		static double area(array<Intelligence::ArrayCoord ^> ^coords);

		bool searchAround(int x, int y, int size);
		Intelligence::GPSCoord^ arrayCoordToGPS(Intelligence::ArrayCoord^ coord);
		int width,height;

	private:
		Intelligence::IntelligenceController ^ intelligenceController;
		Communications::PlaneWatcher ^ planeWatcher;

		Intelligence::ArrayCoord^ gpsToArrayCoord(Intelligence::GPSCoord^ coord);
		array<double>^ getBounds(array<Intelligence::GPSCoord ^> ^coords);

		void construct(array<Intelligence::GPSCoord ^> ^coords, Intelligence::IntelligenceController^ controller);
		void connectLines(array<Intelligence::GPSCoord^> ^coords, short value);
		void drawLine(Intelligence::ArrayCoord ^ start, Intelligence::ArrayCoord ^ stop, short  value);
		void fill(int x, int y, short value);
		double bottomBound, leftBound, topBound,rightBound,widthGPS,heightGPS;
		double widthMeters, heightMeters, BORDER;
		void updateImage();
	};

}
