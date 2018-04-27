//Copyright Asaad 2018 - ∞

#ifndef SLL_H
#define SLL_H

#include <iostream>

template<typename T>
class SLL {

   public:
   
      struct Node {
         T Data;
         Node* Next;
      };
      
      void Insert(const T Data);
      void Update(const T Data , const T UpdatedData);
      void Remove(const T Data);
      void Print() {
         Curr = Head;
         while(Curr != nullptr) {
            std::cout << Curr->Data << " ";
            Curr = Curr->Next;
         }
      }
      
      Node* Find(const T Data) {
         Curr = Head;
         while(Curr->Next != nullptr && Curr->Data != Data)
            Curr = Curr->Next;
         if(Curr->Data == Data) {
            std::cout << "Found Data";
            return Curr;
         } else {
            std::cout << "Could not Find Data in the list \n";
            return nullptr;
         }
      }
      
   private:
   
      Node* Head = nullptr;
      Node* Curr = nullptr;     
};

#endif

template<typename T> void SLL<T>::Insert(const T Data) {
   Node* newNode = new Node();
   newNode->Data = Data;
   newNode->Next = nullptr;
   
   if(Head == nullptr)
      Head = newNode;
   else {
      Curr = Head;
      while(Curr->Next != nullptr)
         Curr = Curr->Next;
      Curr->Next = newNode;
   }
}

template<typename T> void SLL<T>::Update(const T Data , const T UpdatedData) {
   Node* SearchNode = Find(Data);
   if(!SearchNode)
      std::cout << "Could not update Value";
   else 
      SearchNode->Data = UpdatedData;
}

template<typename T> void SLL<T>::Remove(const T Data) {
   Curr = Head;
   Node* Temp = nullptr;
   while(Curr->Next != nullptr && Curr->Data != Data) {
      Temp = Curr;
      Curr = Curr->Next;
   } if(Data == Head->Data) {
      Head = Curr->Next;
      delete Curr;
   } else if(Curr->Data == Data) {
      Temp->Next = Curr->Next;
      delete Curr;
   }
}

int main() {
   SLL<int> Test;
   Test.Insert(1);
   Test.Insert(2);
   Test.Insert(3);
   Test.Insert(4);
   Test.Remove(1);
   Test.Update(1,333);
   Test.Print();
}