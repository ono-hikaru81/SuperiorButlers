#ifndef VECTOR_H
#define VECTOR_H

struct Vec2Int
{
	Vec2Int(int x_, int y_)
	{
		x = x_;
		y = y_;
	}

	int x;
	int y;
};

struct Vec2Float
{
	Vec2Float(float x_, float y_)
	{
		x = x_;
		y = y_;
	}

	float x;
	float y;
};

struct Vec3Int
{
	Vec3Int(int x_, int y_, int z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}

	int x;
	int y;
	int z;
};

struct Vec3Float
{
	Vec3Float(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}

	float x;
	float y;
	float z;
};

#endif // !VECTOR_H
