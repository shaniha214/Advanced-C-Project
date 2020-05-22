
# Project

## Q3

Algorithm: 

```
function Q3(boardPos start, moves, board) {
  boardPosArray = Q1(moves, board);
  matrix = 0;
  matrix[start] = 1;
  helper(start, boardPosArr, matrix);
}

function helper(start, boardPosArray, matrix) {
  newNode->data = createNewNode(start)
  newNode->children = makeList(boardPosArray[TOMOVE(start)], matrix) 

  for (child in list)
    helper(child, boardPosArray, matrix)
}

function makeList(children) {
  for (node in children) 
    if (matrix[node] is 0)
      appendToList(node)
      matrix[node] = 1;
}
```

## TODO

1. assert for all malloc
2. free() in Q1
