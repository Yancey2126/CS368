%% CS368 Spring 2017 Homework Assignment 3 
% * Name: YANG CHEN
% * Due Date: Friday, March 3 by 11:59 pm

clear
header = 'Choose function to test:';
option1 = 'calculateGPA';
option2 = 'calculatePercent - user input';
option3 = 'calculatePercent - file I/O';
option4 = 'quit';

choice = 0;

while choice ~= 4
   choice = menu(header, option1, option2, option3, option4);
   
   switch choice
       case 1
           outFile = input('Enter filename: ', 's');
           disp(['GPA = ', num2str(calculateGPA(outFile))])
           % replace the line above with your code to implement this option
           
       case 2
           exams = input('Enter exams scores: ');
           homeworks = input('Enter homework scores: ');
           quizzes = input('Enter quiz scores: ');
           disp(['Score = ', num2str(calculatePercent(exams, homeworks, quizzes)), '%'])           
           % replace the line above with your code to implement this option
           
       case 3
           inFile = input('Enter input filename: ', 's');
           scores = load(inFile);
           ids = scores(:, 1);
           scores_exam = scores(:, 2:4);
           scores_homework = scores(:, 5:10);
           scores_quiz = scores(:, 11:24);
           percent = calculatePercent(scores_exam, scores_homework, scores_quiz);
           result = [ids, percent];
           outFile = input('Enter output filename: ', 's');
           save(outFile, 'result', '-ascii' );
           % replace the line above with your code to implement this option
           
       otherwise
           disp('quit')
   end
    
end