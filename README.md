# contikiassignment
Yet another assignment. This time using contiki on C.
Here are the requirements, as usual:
Context: To assist in combating the Covid-19 Pandemic, the medical equipment research center is inviting you to participate in the development of a new project. The project consists of a vital signs monitor in a smartwatch. The monitor should record the patient's heart rate (consider between 20 and 140 beats per minute - below 50 will show a low heart rate message, above 90 will display a high heart rate message), oxygen saturation level (consider oxygenation between 80% and 100% - below 90% will show a low saturation message) in the blood, and temperature (consider temperature from 34° to 41° - below 35° will display a hypothermia message, above 37° will show a fever message).

a. Implement a program in Contiki to monitor the vital signs of a person (it should measure heart rate, oxygen saturation, and fever);

b. Three thread process functions should be created, one to monitor each of the vital signs;

c. To simulate the vital signs, random functions should be used;

Pontifical Catholic University of Paraná
Polytechnic School
Bachelor's Degree in Computer Science / Cybersecurity

d. The vital signs (random) should be generated within each of the thread process functions;

e. Print the vital signs in each of the functions;

f. Use the function PROCESS_WAIT_EVENT_UNTIL() configuring a time of three seconds for each thread process function.

g. All thread process functions must explicitly define their termination using the macro PROCESS_END();

h. A fourth thread process function should be created that must wait for an event;

i. Generate an event whenever the vital signs change (consider the normal values for each of the vital signs);

j. The event should generate an alert message for the user;

k. The code must be documented, using comments throughout the program.
