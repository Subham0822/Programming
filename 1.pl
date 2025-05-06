factorial(0, 1).
factorial(N, F):-
    N>0,
    N1 is N-1,
    factorial(N1, F1),
    F is N*F1.

gcd(X,0,X):- X>0.
gcd(X,Y,G):- Y>0, R is X mod Y, gcd(Y, R, G).

even(A):- 0 is A mod 2.
odd(A):- 1 is A mod 2.

employee(001, 'Subham', 'TCS', 'CSE', 'HITK').
employee(002, 'Asmita', 'CTS', 'DS', 'HITK').
employee(003, 'Arnab', 'Amazon', 'IT', 'JU').
employee(004, 'Soumyadip', 'Google', 'CSE', 'IEM').
employee(005, 'Kishalay', 'TCS', 'CSE', 'HITK').

company('A', 'CTS', 'Kolkata').
company('A', 'TCS', 'Delhi').
company('A', 'Amazon', 'Chennai').
company('A', 'Google', 'Bangalore').

q1(EmpID, EmpName, CompID, CompName, Dept, Inst, Location):- employee(EmpID, EmpName, CompName, Dept, Inst), company(CompID, CompName, Location).
q2(EmpID, EmpName, CompID, CompName, Dept, Inst, Location):- employee(EmpID, EmpName, CompName, Dept, Inst), company(CompID, CompName, Location), Inst='HITK', Dept='CSE', Location='Delhi'.

lst_length([], 0).
lst_length([_|T],N):- lst_length(T,N1), N is N1+1.

kth_element([H|_], 1, H).
kth_element([_|T], K, X):-
    K1 is K-1,
    kth_element(T, K1, X).

element_search([X|_],X).
element_search([_|T],X):-
    element_search(T,X).

sum_lst([], 0).
sum_lst([H|T],X):-
    sum_lst(T,S1),
    X is S1+H.

isvowel(X):-member(X,['a','e','i','o','u','A','E','I','O','U']).
isdigit(X):-char_type(X,digit).

check_lst([],[]).
check_lst([H|T],[Type|Rest]):-
    (
        isvowel(H)->Type=vowel;
        isdigit(H)->Type=digit;
        Type=other),
    check_lst(T,Rest).


% Swap two adjacent elements if needed
swap([X, Y | T], [Y, X | T]) :-
    X > Y, !.  % CUT: commit to the swap and don't try other rules

swap([H | T], [H | T1]) :-
    swap(T, T1).

bubble_sort(List, SortedLst):-
    swap(List, NewLst), !,
    bubble_sort(NewLst, SortedLst).

bubble_sort(Sorted, Sorted).
