%% CS368 Spring 2017 Homework Assignment 3 --- calculateGPA.m
% * Name: YANG CHEN
% * Due Date: Friday, March 3 by 11:59 pm

function [GPA] = calculateGPA(filename)
% This function takes the grade and credit of each course and calculate
% the overall average GPA of the student
records = load(filename);
GPA = sum(records(:, 2) .* records(:, 3)) / sum(records(:, 3));
end