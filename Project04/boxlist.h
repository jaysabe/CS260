//defines the BoxList Class
#pragma once
#include "box.h"

class BoxList {
	private:
		struct Node {
			Box box;
			Node * next;

			Node(const Box& aBox) : box(aBox), next(nullptr){}
		};

		Node * head;
		Node * mCurrent;
		int size;
	public:
		BoxList();
		BoxList(const BoxList& other);
		BoxList& operator=(const BoxList& other) = delete;
		~BoxList();

		void addBox(const Box& aBox);
		int getSize() const;
		void startIterating();
		const Box& getNextBox();
		bool hasNextBox() const;
};
