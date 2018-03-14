%% CS368 Spring 2017 Homework Assignment 3 --- calculatePercent.m
% * Name: YANG CHEN
% * Due Date: Friday, March 3 by 11:59 pm

function [Percent] = calculatePercent(exams, homeworks, quizzes)
% The calculatePercent function computes a weighted percentage based on 
% three vectors of scores passed as arguments to the function: 
% exams(60%), homeworks(25%), and quizzes(15%)
Percent = mean(exams,2) + mean(homeworks, 2)/0.3*0.25 + mean(quizzes, 2)/0.1*0.15;
end