%% CS368 Spring 2018 Homework Assignment 1 
% * Name: YANG CHEN
% * Due Date: Monday, February 12 by 11:59 pm


% Writing MATLAB commands 
% Answer the questions by adding code to this MATLAB script.
% Make sure your code demonstrates that your commands are doing the correct 
% thing (by either using the disp() command or by not suppressing the output).

clear

%% Question 1

% a.
q1a = ones(1, 9) * 4
% b. 
q1b = [zeros(2), [0, 9]']
% c.
q1c = (1:8).^2
% d.
q1d = [2:4:18,20:-5:0]
% e.
q1e = diag(1:2:9)
% f. 
q1f = [[zeros(3), ones(3)]', [ones(3)*2, eye(3,3) * 3]']

%% Question 2

data = [ 2 7 4 3; 3 4 7 6; 8 3 5 1; 1 4 2 6; 7 2 2 5 ];
info = [ 1 2 3 4; 3 2 4 1; 2 4 1 3; 4 3 1 2 ];
vec = [ 4 1 9 5 6 3 2 7 8 ];

% a.
q2a = data(2,:)'
% b.
q2b = data(:, 1:3)
% c.
q2c = info(1:2:3, 2:2:4)
% d.
q2d = [data(1, :), data(2, :); info(3, :), info(4, :)]
% e.
vec(2:2:end) = 0
% f.
info(:, 2) = data(3, :)'
% g.
data(:, [1, 4]) = data(:, [4, 1])
