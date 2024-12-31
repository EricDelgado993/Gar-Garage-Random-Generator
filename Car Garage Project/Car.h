#pragma once

// structure for car object
struct Car
{
	string brand;
	string model;
	string color;
	int maxSpeed;
};

// structure for output object
struct Output
{
	string outputBrandPath = "Output\\Brands\\";
	string outputModelPath = "Output\\Models\\";
	string outputColorPath = "Output\\Colors\\";
	string outputSpeedPath = "Output\\Speeds\\";
	string outputStatsPath = "Output\\";
};