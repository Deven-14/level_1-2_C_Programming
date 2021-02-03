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
	int val = 5;
	addHead(s, &val);
	
	ASSERT_EQ(s->head, s->tail);//checking if the addess is same, for value,we have to derederence
	ASSERT_EQ(s->head->data, s->tail->data);//again checking for addresss match, not value
}

TEST_F(singlyLinkedListEdgeTest, addTailWhenListEmpty)
{
	int val = 5;
	addTail(s, &val);
	
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



TEST_F(singlyLinkedListEdgeTest, removeHeadWhenListHasOneEle)
{
	int val = 5;
	addHead(s, &val);
	
	removeHead(s);
	ASSERT_EQ(NULL, s->head);
	ASSERT_EQ(NULL, s->tail);
}

TEST_F(singlyLinkedListEdgeTest, removeTailWhenListHasOneEle)
{
	int val = 5;
	addTail(s, &val);
	
	removeTail(s);
	ASSERT_EQ(NULL, s->head);
	ASSERT_EQ(NULL, s->tail);
}



int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

TEST_F(singlyLinkedListEdgeTest, removeDataWhenListEmpty)
{
	int val = 5;
	ASSERT_EQ(0, removeData(s, &val, compare));
}


class singlyLinkedListAddTest : public testing::Test
{	
	public:
		
		singlyLinkedList *s;
		int *values;
		Iterator *i;
		
		singlyLinkedListAddTest()
		{
			s = newSinglyLinkedList(); 
			i = newIterator(&s);
			values = new int[10]{3,5,3,2,6,7,8,9,3,1};
		}
		
		void SetUp() {}
		void TearDown() {}
		
		~singlyLinkedListAddTest()
		{
			freeIterator(&i);
			freeSinglyLinkedList(&s); 
			delete[] values;
		}

};

TEST_F(singlyLinkedListAddTest, addHeadTest)
{
	int j;
	for(j = 0; j < 10; ++j)
		addHead(s, &values[j]);
	
	ASSERT_EQ(&values[9], s->head->data);
	ASSERT_EQ(&values[0], s->tail->data);

	for(start(i), j = 9; j >= 0; --j, next(i))
		ASSERT_EQ(&values[j], data(i));
}

TEST_F(singlyLinkedListAddTest, addTailTest)
{
	int j;
	for(j = 0; j < 10; ++j)
		addTail(s, &values[j]);
	
	ASSERT_EQ(&values[0], s->head->data);
	ASSERT_EQ(&values[9], s->tail->data);
	
	for(start(i), j = 0; j < 10; ++j, next(i))
		ASSERT_EQ(&values[j], data(i));
}


class singlyLinkedListRemoveTest : public testing::Test
{	
	public:
		
		singlyLinkedList *s;
		Iterator *i;
		int *values;
		
		singlyLinkedListRemoveTest()
		{
			s = newSinglyLinkedList(); 
			i = newIterator(&s);
			values = new int[10]{3,5,3,2,6,7,8,9,3,1};
		}
		
		void SetUp()
		{
			for(int j = 0; j < 10; ++j)
				addTail(s, &values[j]);
		}
		void TearDown() {}
		
		~singlyLinkedListRemoveTest()
		{
			freeSinglyLinkedList(&s); 
			freeIterator(&i);
			delete[] values;
		}

};


TEST_F(singlyLinkedListRemoveTest, removeHeadTest)
{
	for(int j = 0; j < 10; ++j)
	{
		ASSERT_EQ(&values[j], s->head->data);
		removeHead(s);
	}
}


TEST_F(singlyLinkedListRemoveTest, removeTailTest)
{
	for(int j = 9; j >= 0; --j)
	{
		ASSERT_EQ(&values[j], s->tail->data);
		removeTail(s);
	}
}


TEST_F(singlyLinkedListRemoveTest, removeDataTest)
{
	int val = 3;
	removeData(s, &val, compare);
	
	start(i);//******************************very important, coz we are creating iterator first and then we are we are initializing values, so initially i->curr = NULL; so we have to use start function
	
	for(int j = 0; j < 10; ++j)
	{
		if(values[j] == 3)
			continue;
		ASSERT_EQ(&values[j], data(i));
		next(i);
	}
}


int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}