# A*-Algorithm



> Explanation

        | A* Algorithm > A smart path finding algorithm
        
        | Core of algorithm > Based on heuristic
        
        | Make use of 3 variables [ F, G, H ]...
        
                            > [ G ] - distance between current node and start node
                            > [ H ] - heuristic  ( possible distance from current node to target node )
                            > [ F ] - total cost of node [ F = G + H ]

        | Dijkstra's has no idea which node is best
        
        | A* jumps on the node with lowest [ F ] - Best option to reach target


        | Steps...

                1. Add the starting node to the Open List

                2. Repeat following...

                    a. Find the node with lowest [ F ] in the Open List ( call it currentNode ).

                    b. Put it to the Closed List. ( mark as visited )

                    c. For each of its neighbors...

                        > If valid or in the Closed List...
                            [ Ignore ]

                        > If it is not in the Open List...
                            [ Add it to the Open List ]
                            [ Find G, H and F of node ]

                        > If it is on the Open List...
                            [ Check if G is better than its parent (currentNode) ]
                                [ if yes > better option ]
                                    [ add it to Open List ]

                    d. If current node = to target OR failed finding target
                        > STOP

                3. Finish

# Code execution

### Sample input

![input](https://github.com/l4z0-space/A-Star-Algorithm/blob/master/imgs/input.PNG)

### Output
> Path showed with 'x'

![output](https://github.com/l4z0-space/A-Star-Algorithm/blob/master/imgs/output.PNG)


