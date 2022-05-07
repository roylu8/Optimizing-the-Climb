#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>

#include "../Graph.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

#include "../cs225/catch/catch.hpp"

using namespace cs225;

TEST_CASE("Test file works")
{
    REQUIRE(1 * 5 == 5);
}

TEST_CASE("Correctly assigned index to image")
{
    PNG image, image2;
    image.readFromFile("tests/5by5test.png");
    image2.readFromFile("tests/700by700test.png");
    Graph testGraph(image);
    Graph testGraph2(image2);
    vector<int> correctVector;
    vector<int> correctVector2;
    for (unsigned i = 0; i < image.height() * image.width(); i++)
    {
        correctVector.push_back(i);
    }
    for (unsigned i = 0; i < image2.height() * image2.width(); i++)
    {
        correctVector2.push_back(i);
    }

    REQUIRE(testGraph.getIndex() == correctVector);
    REQUIRE(testGraph2.getIndex() == correctVector2);
}

TEST_CASE("Correctly assigned luminnance to each index")
{
    PNG image, image2;
    image.readFromFile("tests/5by5test.png");
    image2.readFromFile("tests/700by700test.png");
    Graph testGraph(image);
    Graph testGraph2(image2);
    vector<int> correctLuminance;
    vector<int> correctLuminance2;
    for (unsigned i = 0; i < image.height(); i++)
    {
        for (unsigned j = 0; j < image.width(); j++)
        {
            HSLAPixel &pixel = image.getPixel(j, i);
            correctLuminance.push_back(abs((pixel.l * 10) - 10));
        }
    }
    for (unsigned i = 0; i < image2.height(); i++)
    {
        for (unsigned j = 0; j < image2.width(); j++)
        {
            HSLAPixel &pixel = image2.getPixel(j, i);
            correctLuminance2.push_back(abs((pixel.l * 10) - 10));
        }
    }

    REQUIRE(testGraph.getLuminance() == correctLuminance);
    REQUIRE(testGraph2.getLuminance() == correctLuminance2);
}

TEST_CASE("Adjacency list size is correct")
{
    PNG image, image2;
    image.readFromFile("tests/5by5test.png");
    image2.readFromFile("tests/700by700test.png");
    int count = 0, count2 = 0;
    for (unsigned i = 0; i < image.width(); i++)
    {
        for (unsigned j = 0; j < image.height(); j++)
        {
            count++;
        }
    }
    for (unsigned i = 0; i < image2.width(); i++)
    {
        for (unsigned j = 0; j < image2.height(); j++)
        {
            count2++;
        }
    }
    Graph testGraph(image);
    Graph testGraph2(image2);

    REQUIRE(testGraph.getSize() == count);
    REQUIRE(testGraph2.getSize() == count2);
}

TEST_CASE("Dijkstra's test case small")
{
    PNG input;
    input.readFromFile("tests/5by5obvious.png");
    Graph generatedGraph(input);
    generatedGraph.Dijkstras(0, 24);
    generatedGraph.Render(input);

    PNG finalResult;
    finalResult.readFromFile("images/result.png");

    PNG correctResult;
    correctResult.readFromFile("tests/5by5obviousanswerall.png");

    REQUIRE(finalResult == correctResult);
}

TEST_CASE("Dijkstra's test case big")
{
    PNG input;
    input.readFromFile("tests/20by20test.png");
    Graph generatedGraph(input);
    generatedGraph.Dijkstras(0, 399);
    generatedGraph.Render(input);

    PNG finalResult;
    finalResult.readFromFile("images/result.png");

    PNG correctResult;
    correctResult.readFromFile("tests/20by20answer.png");

    REQUIRE(finalResult == correctResult);
}

TEST_CASE("Dijkstra's test case large")
{
    PNG input;
    input.readFromFile("tests/700by700test.png");
    Graph generatedGraph(input);
    generatedGraph.Dijkstras(0, 290000);
    generatedGraph.Render(input);

    PNG finalResult;
    finalResult.readFromFile("images/result.png");

    PNG correctResult;
    correctResult.readFromFile("tests/700by700answer.png");

    REQUIRE(finalResult == correctResult);
}

TEST_CASE("A*'s test case small")
{
    PNG input;
    input.readFromFile("tests/5by5obvious.png");
    Graph generatedGraph(input);
    generatedGraph.A_Star(0, 24);
    generatedGraph.A_StarRender(input);

    PNG finalResult;
    finalResult.readFromFile("images/resultA.png");

    PNG correctResult;
    correctResult.readFromFile("tests/5by5obviousanswerall.png");

    REQUIRE(finalResult == correctResult);
}

TEST_CASE("A*'s test case big")
{
    PNG input;
    input.readFromFile("tests/20by20test.png");
    Graph generatedGraph(input);
    generatedGraph.A_Star(0, 399);
    generatedGraph.A_StarRender(input);

    PNG finalResult;
    finalResult.readFromFile("images/resultA.png");

    PNG correctResult;
    correctResult.readFromFile("tests/20by20answerA.png");

    REQUIRE(finalResult == correctResult);
}

TEST_CASE("A*'s test case large")
{
    PNG input;
    input.readFromFile("tests/700by700test.png");
    Graph generatedGraph(input);
    generatedGraph.A_Star(0, 290000);
    generatedGraph.A_StarRender(input);

    PNG finalResult;
    finalResult.readFromFile("images/resultA.png");

    PNG correctResult;
    correctResult.readFromFile("tests/700by700answerA.png");

    REQUIRE(finalResult == correctResult);
}