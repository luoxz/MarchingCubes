//#pragma once
//
//#include<forward_list>
//#include "CoreMinimal.h"
//#include "TransitionDirection.h"
//
//struct FBoolVector
//{
//	bool X;
//	bool Y;
//	bool Z;
//
//	FBoolVector(bool x, bool y, bool z) : X(x), Y(y), Z(z)
//	{
//	}
//};
//
//
//struct VertexProperties
//{
//	bool IsNearXMin;
//	bool IsNearXMax;
//
//	bool IsNearYMin;
//	bool IsNearYMax;
//
//	bool IsNearZMin;
//	bool IsNearZMax;
//
//	bool IsNormalOnly;
//};
//
//struct VertexProperties2D
//{
//	int X;
//	int Y;
//
//	bool IsXExact;
//	bool IsYExact;
//
//	bool NeedTranslation;
//
//	TransitionDirection Direction;
//};
//
//struct IRegularVoxel
//{
//	virtual ~IRegularVoxel()
//	{
//	}
//	virtual float GetValue(int X, int Y, int Z) = 0;
//	virtual FColor GetColor(int X, int Y, int Z) = 0;
//	virtual void SaveVertex(int X, int Y, int Z, short EdgeIndex, int Index, VertexProperties Properties) = 0;
//	virtual int LoadVertex(int X, int Y, int Z, short Direction, short EdgeIndex) = 0;
//	virtual bool IsNormalOnly(FVector vertex) = 0;
//};
//
//struct ITransitionVoxel
//{
//	virtual ~ITransitionVoxel()
//	{
//	}
//	virtual float GetValue2D(int X, int Y) = 0;
//	virtual FColor GetColor2D(int X, int Y) = 0;
//	virtual void SaveVertex2D(int X, int Y, short EdgeIndex, int Index) = 0;
//	virtual int LoadVertex2D(int X, int Y, short Direction, short EdgeIndex) = 0;
//	virtual TransitionDirection GetDirection() = 0;
//};
//
//typedef std::forward_list<int> Trigs;
//typedef std::forward_list<FVector> Verts;
//typedef std::forward_list<FColor> Colors;
//typedef std::forward_list<VertexProperties> Props;
//typedef std::forward_list<VertexProperties2D> Props2D;
//
//
//namespace TransvoxelTools
//{
//	void RegularPolygonize(IRegularVoxel* const Chunk, const int X, const int Y, const int Z, const short ValidityMask, Trigs& Triangles, int& TrianglesCount, Verts& Vertices,
//						   Props& Properties, Colors& Colors, int& VerticesCount, const int Step);
//
//	int AddVertex(IRegularVoxel* const Chunk, const int Step, Verts& Vertices, Props& Properties, Colors& Colors, int& VerticesCount, const FVector Vertex,
//				  const FIntVector ExactPosition, const FBoolVector IsExact, const FColor RGColor);
//
//
//	FVector InterpolateX(IRegularVoxel* const Chunk, const int MinX, const int MaxX, const int Y, const int Z);
//	FVector InterpolateY(IRegularVoxel* const Chunk, const int X, const int MinY, const int MaxY, const int Z);
//	FVector InterpolateZ(IRegularVoxel* const Chunk, const int X, const int Y, const int MinZ, const int MaxZ);
//
//
//
//
//
//	void TransitionPolygonize(ITransitionVoxel* const Chunk, const int X, const int Y, const short ValidityMask, Trigs& Triangles, int& TrianglesCount, Verts& Vertices,
//							  Props2D& Properties, Colors& Colors, int& VerticesCount, const int Step);
//
//	int AddVertex(ITransitionVoxel* const Chunk, const bool bIsTranslated, Verts& Vertices, Props2D& Properties, Colors& Colors, int& VerticesCount,
//				  const FVector Vertex, const FIntVector ExactPosition, const FBoolVector IsExact);
//
//
//	FVector InterpolateX2D(ITransitionVoxel* const Chunk, const int MinX, const int MaxX, const int Y);
//	FVector InterpolateY2D(ITransitionVoxel* const Chunk, const int X, const int MinY, const int MaxY);
//
//
//	FVector GetTranslated(const FVector V, const FVector N, const VertexProperties P, const TArray<bool, TFixedAllocator<6>> ChunkHasHigherRes, const int Depth);
//};