//Copyright Asaad 2018 - ∞

class Node {
   constructor(Data,Next) {
      this.Data = Data;
      this.Next = Next;
   }
}

class SLL {
   constructor() {
      this.Head = null;
      this.Curr = null;
   }
   
   Insert(Data) {
      this.newNode = new Node(Data,null);
      if(this.Head == null)
         this.Head = this.newNode;
      else {
         this.Curr = this.Head;
         while(this.Curr.Next != null) {
            this.Curr = this.Curr.Next;
         } this.Curr.Next = this.newNode;
      }
   }
   
   Find(Data) {
      this.Curr = this.Head;
      while(this.Curr.Next != null && this.Curr.Data != Data)
         this.Curr = this.Curr.Next;
      if(this.Curr.Data === Data) 
         return this.Curr;
      else
         return null;
    }
    
    Update(Data,UpdatedData) {
       this.SearchNode = this.Find(Data);
       if(!this.SearchNode)
          console.log("Failed to update the data");
       this.SearchNode.Data = UpdatedData;
    }
   
   Remove(Data) {
      this.Curr = this.Head;
      this.Temp = new Node(null,null);
      while(this.Curr.Next != null && this.Curr.Data != Data) {
         this.Temp = this.Curr;
         this.Curr = this.Curr.Next;
      } if(this.Data === this.Head.Data) {
         this.Head = this.Curr.Next;
         this.Curr = null;
      } else if(this.Curr.Data === Data) {
         this.Temp.Next = this.Curr.Next;
         this.Curr = null;
      }
   }
   
   Print() {
      this.Curr = this.Head;
      while(this.Curr != null) {
         console.log(this.Curr.Data + " ");
         this.Curr = this.Curr.Next;
      }
   }
}

var Test = new SLL();

Test.Insert(1);
Test.Insert(2);
Test.Insert(3);

Test.Update(1,111);
Test.Remove(2);

Test.Print();
