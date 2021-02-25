#pragma once
template <class T>
struct SNode
{
	T* m_pData;
	SNode* m_pLink = nullptr;

	SNode(T data)
	{
		m_pData = new T(data);
	}
};

template <class T>
class CStack
{
private:
	SNode<T>* m_pFront;
	SNode<T>* m_pBack;
	int m_nSize;

public:
	CStack()
		:m_nSize(0), m_pBack(nullptr),
		m_pFront(nullptr)
	{}

	~CStack() {
		if (m_pFront != nullptr)
		{
			for (int i = 1; i < m_nSize; i++)
			{
				SNode<T>* removing = m_pBack;
				m_pBack = m_pBack->m_pLink;

				delete removing->m_pData;
				delete removing;
			}
			delete m_pBack->m_pData;
			delete m_pBack;

			m_pFront = nullptr;
			m_pBack = nullptr;
		}
	}



	T Top(void) const { return *m_pBack->m_pData; }
	int Size(void) const { return m_nSize; }
	bool Empty(void) { return m_nSize; }


	void Push(T data)
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
			newNode->m_pLink = m_pBack;
			m_pBack = newNode;
		}
		++m_nSize;
	}

	void Pop(void)
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
				m_pBack = m_pBack->m_pLink;

				delete removing->m_pData;
				delete removing;
			}
		}
		--m_nSize;
	}

};
