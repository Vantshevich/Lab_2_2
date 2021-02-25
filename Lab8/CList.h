#pragma once
template <class T>
struct SNode
{
	T* m_pData;
	SNode* m_pNext = nullptr;
	SNode* m_pPrevious = nullptr;

	SNode(T data)
	{
		m_pData = new T(data);
	}
};

template <class T>
class CList
{
private:
	SNode<T>* m_pFront;
	SNode<T>* m_pBack;
	int m_nSize;

public:
	CList()
		:m_nSize(0), m_pBack(nullptr),
		m_pFront(nullptr)
	{}

	CList(int number, T value)
		:m_nSize(number)
	{
		SNode<T>* newNodeFirst = new SNode<T>(value);
		m_pFront = newNodeFirst;
		m_pBack = newNodeFirst;
		for (int i = 1; i < m_nSize; i++) 
		{
			SNode<T>* newNode = new SNode<T>(value);
			m_pBack->m_pNext = newNode;
			m_pBack = newNode;
		}
	}

	~CList() {
		while (m_nSize--) {
			SNode<T>* removing = m_pFront;
			m_pFront = m_pFront->m_pNext;

			delete removing->m_pData;
			delete removing;
		}
	}



	T Front(void) const { return *m_pFront->m_pData; }
	T Back(void) const { return *m_pBack->m_pData; }
	int Size(void) const { return m_nSize; }
	bool Empty(void) { return m_nSize; }


	void Push_Back(T data)
	{
		if (m_pFront == nullptr)
		{
			SNode<T>* newNode = new SNode<T>(data);
			m_pFront = newNode;
			m_pBack = newNode;
		}
		else
		{
			SNode<T>* newNode = new SNode<T>(data);
			m_pBack->m_pNext = newNode;
			newNode->m_pPrevious = m_pBack;
			m_pBack = newNode;
		}
		++m_nSize;
	}

	void Push_Front(T data)
	{
		if (m_pFront == nullptr)
		{
			SNode<T>* newNode = new SNode<T>(data);
			m_pFront = newNode;
			m_pBack = newNode;
		}
		else
		{
			SNode<T>* newNode = new SNode<T>(data);
			m_pFront->m_pPrevious = newNode;
			newNode->m_pNext = m_pFront;
			m_pFront = newNode;
		}
		++m_nSize;
	}


	void Pop_Front(void)
	{
		if (m_pFront != nullptr)
		{
			if (m_nSize == 1)
			{
				delete m_pFront->m_pData;
				delete m_pFront;

				m_pFront = nullptr;
				m_pBack = nullptr;
			}
			else
			{
				SNode<T>* removing = m_pFront;
				m_pFront = m_pFront->m_pNext;
				m_pFront->m_pPrevious = nullptr;

				delete removing->m_pData;
				delete removing;
			}
		}
		--m_nSize;
	}

	void Pop_Back(void)
	{
		if (m_pFront != nullptr)
		{
			if (m_nSize == 1)
			{
				delete m_pFront->m_pData;
				delete m_pFront;

				m_pFront = nullptr;
				m_pBack = nullptr;
			}
			else
			{
				SNode<T>* removing = m_pBack;
				m_pBack = m_pBack->m_pPrevious;
				m_pBack->m_pNext = nullptr;

				delete removing->m_pData;
				delete removing;
			}
		}
		--m_nSize;
	}

	void Clear(void)
	{
		if (m_pFront != nullptr)
		{
			for (int i = 1; i < m_nSize; i++)
			{
				SNode<T>* removing = m_pFront;
				m_pFront = m_pFront->m_pNext;
				m_pFront->m_pPrevious = nullptr;

				delete removing->m_pData;
				delete removing;
			}
			delete m_pFront->m_pData;
			delete m_pFront;

			m_pFront = nullptr;
			m_pBack = nullptr;
		}
	}

};
