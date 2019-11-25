#include "pch.h"
#include "CppUnitTest.h"
#include "GraphDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace GraphUnitTests
{

	TEST_CLASS(GraphUnitTests)
	{
	public:
		
		TEST_METHOD(Constructor1)
		{
			Graphs g = Graphs(3);
			Assert::IsTrue(g.getVertices() == 3);
		}

		TEST_METHOD(Constructor2)
		{
			vector<vector<int>> vecMain;
			vector<int> vec1;
			vector<int> vec2;
			vec1.push_back(0);
			vec1.push_back(1);
			vec2.push_back(2);
			vec2.push_back(3);
			vecMain.push_back(vec1);
			vecMain.push_back(vec2);
			Graphs g = Graphs(vecMain);
			Assert::IsTrue(g.getVertices() == 2);
		}
		TEST_METHOD(Has_Edge1)
		{
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(3, 1);
			g.addEdge(2, 2);

			Assert::IsTrue(g.hasEdge(0, 1));
			Assert::IsTrue(g.hasEdge(3, 1));
			Assert::IsTrue(g.hasEdge(2, 2));
		}

		TEST_METHOD(Has_Edge2)
		{
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(3, 2);
			g.addEdge(2, 1);

			Assert::IsFalse(g.hasEdge(0, 2));
			Assert::IsTrue(g.hasEdge(3, 2));
			Assert::IsFalse(g.hasEdge(2, 2));
		}

		TEST_METHOD(Add_Edge1)
		{
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(2, 1);
			g.addEdge(3, 1);

			Assert::IsTrue(g.hasEdge(0, 1));
			Assert::IsTrue(g.hasEdge(3, 1));
			Assert::IsFalse(g.hasEdge(2, 3));
		}

		TEST_METHOD(Add_Edge2)
		{
			Graphs g = Graphs(3);
			g.addEdge(0, 1);
			g.addEdge(2, 1);
			g.addEdge(1, 2);

			Assert::IsTrue(g.hasEdge(0, 1));
			Assert::IsTrue(g.hasEdge(2, 1));
			Assert::IsTrue(g.hasEdge(1, 2));
		}

		TEST_METHOD(Remove_Edge1) {
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(2, 3);
			g.addEdge(2, 1);
			g.addEdge(1, 3);
			g.addEdge(3, 0);
			g.addEdge(0, 2);

			//all of 2s connections
			Assert::IsTrue(g.hasEdge(2, 3));
			Assert::IsTrue(g.hasEdge(2, 1));
			Assert::IsTrue(g.hasEdge(0, 2));

			//remove some edges
			g.removeEdge(2, 3);
			Assert::IsFalse(g.hasEdge(2, 3));
			g.removeEdge(2, 1);
			Assert::IsFalse(g.hasEdge(2, 1));
			g.removeEdge(0, 2);
			Assert::IsFalse(g.hasEdge(0, 2));
		}

		TEST_METHOD(Remove_Edge2) {
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(2, 3);
			g.addEdge(2, 1);
			g.addEdge(1, 3);
			g.addEdge(3, 0);
			g.addEdge(0, 2);

			Assert::IsTrue(g.hasEdge(0, 1));
			Assert::IsTrue(g.hasEdge(1, 3));
			Assert::IsTrue(g.hasEdge(3, 0));

			//remove some edges
			g.removeEdge(0, 1);
			Assert::IsFalse(g.hasEdge(0, 1));
			g.removeEdge(1, 3);
			Assert::IsFalse(g.hasEdge(1, 3));
			g.removeEdge(3, 0);
			Assert::IsFalse(g.hasEdge(3, 0));
		}

		TEST_METHOD(outEdge1) {
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(2, 3);
			g.addEdge(2, 1);
			g.addEdge(1, 3);
			g.addEdge(3, 0);
			g.addEdge(0, 2);
			vector<int> vec;
			vec.push_back(1);
			vec.push_back(3);
			Assert::IsTrue(g.outEdge(2) == vec);
		}

		TEST_METHOD(outEdge2) {
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(2, 3);
			g.addEdge(2, 1);
			g.addEdge(1, 3);
			g.addEdge(3, 0);
			g.addEdge(0, 2);
			vector<int> vec;
			vec.push_back(0);
			vec.push_back(3);
			Assert::IsFalse(g.outEdge(0) == vec);
		}

		TEST_METHOD(inEdge1) {
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(2, 3);
			g.addEdge(2, 1);
			g.addEdge(1, 3);
			g.addEdge(3, 0);
			g.addEdge(0, 2);
			vector<int> vec;
			vec.push_back(0);
			vec.push_back(2);
			Assert::IsTrue(g.inEdge(1) == vec);
		}

		TEST_METHOD(inEdge2) {
			Graphs g = Graphs(4);
			g.addEdge(0, 1);
			g.addEdge(2, 3);
			g.addEdge(2, 1);
			g.addEdge(1, 3);
			g.addEdge(3, 0);
			g.addEdge(0, 2);
			vector<int> vec;
			vec.push_back(0);
			vec.push_back(1);
			Assert::IsFalse(g.inEdge(3) == vec);
		}

		TEST_METHOD(Destructor)
		{
			/*Graphs g = Graphs(4);
			Assert::AreEqual(4, g.getVertices());
			g.~Graphs();
			int deadVert = g.getVertices();
			Assert::AreEqual(0, deadVert);*/
		}
	};
}
