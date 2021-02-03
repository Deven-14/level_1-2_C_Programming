#include <iostream>
#include <gtest/gtest.h>


extern "C"
{
	#include <singlyLinkedList.h>
}


using namespace std;


class singlyLinkedListEdgeTest : public testing::Test
{	
	public:
		
		singlyLinkedList *s;
	
		singlyLinkedListEdgeTest() { s = newSinglyLinkedList(); }
		
		~singlyLinkedListEdgeTest() { freeSinglyLinkedList(&s); }

};

TEST_F(singlyLinkedListEdgeTest, addHeadWhenListEmpty)
{
	int data = 5;
	addHead(s, &data);
	
	ASSERT_EQ(s->head, s->tail);//checking if the addess is same, for value,we have to derederence
	ASSERT_EQ(s->head->data, s->tail->data);//again checking for addresss match, not value
}

TEST_F(singlyLinkedListEdgeTest, addTailWhenListEmpty)
{
	int data = 5;
	addTail(s, &data);
	
	ASSERT_EQ(s->head, s->tail);
	ASSERT_EQ(s->head->data, s->tail->data);
}

TEST_F(singlyLinkedListEdgeTest, removeHeadWhenListEmpty)
{
	ASSERT_EQ(-1, removeHead(s));
}

TEST_F(singlyLinkedListEdgeTest, removeTailWhenListEmpty)
{
	ASSERT_EQ(-1, removeTail(s));
}

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

TEST_F(singlyLinkedListEdgeTest, removeDataWhenListEmpty)
{
	int data = 5;
	ASSERT_EQ(0, removeData(s, &data, compare));
}


class singlyLinkedListTest : public testing::Test
{	
	public:
		
		singlyLinkedList *s;
		int *data;
		Iterator *i;
		
		singlyLinkedListTest()
		{
			s = newSinglyLinkedList(); 
			i = newIterator(&s);
			data = new int[10]{3,5,3,2,6,7,8,9,3,1};
		}
		
		void SetUp() {}
		void TearDown() {}
		
		~singlyLinkedListTest()
		{
			freeIterator(&i);
			freeSinglyLinkedList(&s); 
			delete[] data;
		}

};

TEST_F(singlyLinkedListTest, addHeadTest)
{
	int j;
	for(j = 0; j < 10; ++j)
		addHead(s, &data[j]);
	
	ASSERT_EQ(&data[9], s->head->data);
	ASSERT_EQ(&data[0], s->tail->data);

	for(start(i), j = 9; j >= 0; --j, next(i))
		ASSERT_EQ(&data[j], data(i));
}

TEST_F(singlyLinkedListTest, addTailTest)
{
	int j;
	for(j = 0; j < 10; ++j)
		addTail(s, &data[j]);
	
	ASSERT_EQ(&data[0], s->head->data);
	ASSERT_EQ(&data[9], s->tail->data);
	
	for(start(i), j = 0; j < 10; ++j, next(i))
		ASSERT_EQ(&data[j], data(i));
}

//THERE IS AN ERROR HERE, THE FUNCTION OF ITERATOR IS ALSO NAMED data(i) AND THE member data in the test fixture is also named int *data; so there was an error called expression cannot be used as a function

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}