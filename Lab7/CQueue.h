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
class CQueue
{
private:
	SNode<T>* m_pFront;
	SNode<T>* m_pBack;
	int m_nSize;

public:
	CQueue()
		:m_nSize(0), m_pBack(nullptr),
		m_pFront(nullptr)
	{}

	~CQueue() {
		while (m_nSize--) {
			SNode<T>* removing = m_pFront;
			m_pFront = m_pFront->m_pLink;
			
			delete removing->m_pData;
			delete removing;
		}
	}



	T Front(void) const { return *m_pFront->m_pData; }
	T Back(void) const { return *m_pBack->m_pData; }
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
			m_pBack->m_pLink = newNode;
			m_pBack = newNode;
		}
		++m_nSize;
	}

	void Pop(void)
	{
		if (m_nSize == 1) 
		{
			SNode<T>* removing = m_pFront;
			m_pFront = m_pFront->m_pLink;

			delete removing->m_pData;
			delete removing;

			m_pFront = nullptr;
			m_pBack = nullptr;
		}
		else
		{
			if (m_pFront != nullptr) {
				SNode<T>* removing = m_pFront;
				m_pFront = m_pFront->m_pLink;

				delete removing->m_pData;
				delete removing;
			}
		}
		--m_nSize;
	}
	
};
