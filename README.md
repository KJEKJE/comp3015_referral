# COMP3015 Referral Project: Untitled, but Shiny

### Introduction
This is the main repository used for my experimentations and my final version of this C++/OpenGL portfolio.
I wasn’t exactly sure how to go about writing this, so I went about it how I would go about most reports, chaotically consistent.

I started off by going through the respective labs taught across the module. It’s been really interesting learning these part by part, and I very much appreciate the steps provided to get there. There are, in fact, a lot of things of which I would have loved to have implemented into the project but will have to shelve for a later time.

‘Untitled, but Shiny’ is the proposed name for this COMP3015 project, using the Lab1 template as a basis to go off. Of course, as I was relearning my stuff over combined lab learning, there are a few assets and scripts present from where I was going through the lab videos provided. Some code is bound to overlap and be similar, however I’ve tried my best to be consistent and original where I can. The steps to get to where I am in my project were done by me and me alone, but the guidance to move forward are credited at the end of this report.

### Process
There were numerous elements I used in order to produce the final project I submitted. I started off by sketching out a rough idea of what I wanted to showcase, and it's no surprise that I was going to try for something ambitious.. ^^;

![ideation](https://github.com/KJEKJE/comp3015_referral/assets/55700917/7acc0c84-7f00-45c5-aae7-ab9f1ac02d2d)
![ideation2](https://github.com/KJEKJE/comp3015_referral/assets/55700917/21795194-be60-4846-a1f4-831b2337a4c6)

The proposed idea I had but knew that was not going to get it all done in the time provided, was to have multiple models moving in 3D space at the same time, showcasing both the toon shading elements and physics-based reflections depicted through spotlights explored early in the module. I hoped that by combining these it would give off quite the result!

I started out by setting up the GitHub repository to have a C++ git-ignore but learnt quickly that a lot of files will be changing throughout each new program created. With more time, I would have found a way around time, but was left to deal with it for now and expect a huge file in future. Apologies in advance!

Once added, I got the Lab1 templates and started going through the other labs to consolidate my learning.

![no lit phong](https://github.com/KJEKJE/comp3015_referral/assets/55700917/b0571a32-2b9e-43e4-99e7-27b719745e7a)

I got Blinn Phong working to shine a blue light on the torus, and then learnt how to add multiple models into one constructor.

![flat shades](https://github.com/KJEKJE/comp3015_referral/assets/55700917/df4ceab5-bb57-4b0f-ba1f-3f83bdbff969)

Once an object loader was implemented, I then spent time trying to have it load in models I built on Blender. These models have their own vertices and normal, and were switched in.

After, I successfully added in a spotlight that was demonstrated using a plane for reference. That plane would continue throughout my project as a way of understanding transformation and rotation in the space provided. Toon shading was then implemented in. The toon shading can be changed using the const level variables to change up how light interacts with the models at hand.

![the two hour error](https://github.com/KJEKJE/comp3015_referral/assets/55700917/98706445-39e2-421a-b054-4a6bbd90a375)

Once that was done, I spent a lot of time trying to figure out why my project wasn’t combining as intended whenever a fragment shader was being updated, and it turned out that I spent 3 hours looking for a vec3 position instead of a vec4.

![one number vs two hours](https://github.com/KJEKJE/comp3015_referral/assets/55700917/37b26679-776e-4be8-b40f-a42c5906f2ed)

Painful.

Once all figured out, I was able to move onto PBR, having to leave fog alone due to (you guessed it) time. I did want to add a second light, so another light denoted as “Light[1]” was implemented in hopes that I would use it in future. Turns out I did, as it was a great way of showcasing the PBR technique.
The PBR can be tweaked given that the key equations taught in Lab10 were there to establish the base parameters for iterating in future. This meant, unfortunately, that there is a lot of older code that needed to be commented out which would allow Phong and Blinn Phong shading to independently work in the project.
Once I got to here with the last set of Materials parsing through correctly, I got to here:

![Screenshot 2023-08-21 155042](https://github.com/KJEKJE/comp3015_referral/assets/55700917/2b2dcd09-068d-40aa-887f-be21391a64d5)

I was quite happy to leave it there and there, however I wanted to make it dynamic. Using the animate() methods, I was able to have the project successfully rotate about the ‘angle’ variables changing over time. The animation can be paused using the space key, but I unfortunately did not have time to add in left and right movement due to clashes with key finder and the main provided in the Lab1 template.

With the colour tweaks as well, I used calculations for rgb to determine each model's respective colours, as shown in my comments by the "Colour.XXX" code. A few more colour tweaks, and it was done!

![Screenshot 2023-08-21 174613](https://github.com/KJEKJE/comp3015_referral/assets/55700917/df6b68b1-219e-4408-9dc0-70a8567de4ad)

### Result:
Combining both the flat shading elements of toon shading with PBR resulted in quite the combination, denoted by the tri/quad faces interacting with the rotating lights.

The project is available and can be run in Visual Studio 2022 using the Windows Debugger. I ran into a few issues with the full build, as it says that it successfully compiled, but closes on startup? A bit odd and one I cannot resolve in the time given, but thrilled to see the result on Visual Studio.

### Evaluation:
A stretch goal with more time would have included the grassling enemy to have been under a base fog shader the further away they were spawned from the centre of the layout. Speaking of which, the model layouts were created on Blender. I spent some of my time during the module to brush up on my skills on this software to have models uniquely implemented in, as per requirements for the project.

![close-up version of inside the forest](https://github.com/KJEKJE/comp3015_referral/assets/55700917/5b87acb3-eace-41c6-874f-cbceaf6ae715) ![blender shanopi](https://github.com/KJEKJE/comp3015_referral/assets/55700917/0701656a-36c6-4934-8807-1dc786515465)

Using the <objmesh> cpp file as a baseline for my understanding, I was able to successfully input the blender files made to interact with the 3D space. Each model has a series of vertex points with were then inputted into the scenebasic_uniform files for loading in. With more time, I would have made it so that the ground had a more grassy-like texture, but settled with roughness and metallic variations between models.

![into the forest](https://github.com/KJEKJE/comp3015_referral/assets/55700917/3a93527c-9229-4d99-808a-48fe9fe89966)

A projectile with its own multilight that spawned on press would have been PHENOMENAL, however, as I was unable to get the key inputs functioning consistently, I had to shelve the idea for a future cleaner iteration. Same thing for the swamp enemy to have had a surface animation, but as I did not get round to adding textures, this also had to be shelved.

Disintegration and particle animations to showcase the ‘death’ of a model loaded in were ideated but certainly not intended to be attempted for this referred work due to time. Ideas like this fuel me to keep working on my projects for future :]

A lot of trial and error was done to ensure that specific values like Ks and Kd were kept separate to avoid clashes with parsing. With more time, I would like to go over my project and clean-up redundant code of shift them into their own tidied-up methods, but to just get the project working in that timeframe was challenging enough. There are a lot of coding practices here where I could have done better, but time will always be a determining factor for getting this more optimised.

![Screenshot 2023-08-21 175106](https://github.com/KJEKJE/comp3015_referral/assets/55700917/e16eb9ab-1eb2-476a-850a-5637064b0a4a)

### Troubleshooting:
Regarding dependencies and struggles to load it on Visual Studio, please do note a few things first!

-	Dependencies at the current moment are mapped to the dependencies folder mapped on the Github repository. This was because there was no other suitable way of maintaining version control given the time I was provided. If this is the issue and if you have your own dependencies folder, please ensure to map them there instead.
-	Failing that, a OneDrive link is also provided in the Feature Declaration sheet (marking specific)
-	I was unsure in marking if there was meant to be a final ‘build’ as such, as I’m unsure if this was ever covered across either module. That said, the project should run perfectly in Visual Studio code.
-	The project also uses #version 460 gl libraries, found in the project’s dependencies folder. Note that some are subject to disappear because GitHub really likes telling me... what is not there :/

As mentioned in my submission, a lot of my hand-ins related to this project are going to be a bit jumbled up due to the git-ignores for this repository being temperamental, so I will be rather unsurprised to hear that the project doesn’t fully compile at its current state. That said, everything should be available if not here in this repository, then definitely on my university OneDrive.

I’ll be sure to optimise this process over time, as I would like to keep hold of this and polish it in future.

### Specific Credits and Thanks:
Lab templates of 1-10 provided on the COMP3015 university page, specifically the plane mesh used to position the mvp of the project (acting as the purple swamp terrain) and the plane mesh used for demonstrating the PBR. The helper files were used for my understanding of different shading techniques, but the scenerunner and scenebasic elements were the others utilised for this project.

Some assets, while unused, are still present in the project and have not been removed yet due to time constraints to get the project finished. This includes the spot_triangulated cow meshes used for PBR, as well as the torus, triangle and teapot meshes used in labs 1-4. These were of course replaced to suit my blender models, but the guidance is still beneficial the same, and acts as a result of my working thought process.

The <objmesh> file reader is one to note, as explained in my previous module, my filereader had issues with reading in objs catered to specifically blender objects, and due to time I would have struggled to finish the project without a base template one. Credit is given for the starting template to work from in order to showcase the shaders element, rather than my vao/vbo knowledge.

While not fully implemented, credit is also given to “Windows.h” and “MMSystem.h”, as these libraries would have been used for adding a soundtrack to the project. The static key finders found in the glfw libraries are also worth noting, as I would have used these as my primary source for inputting controls.

### Rounding Off and Disclaimer:
Apologies that this is quite the long read, but I felt that I NEEDED to get this out at least on paper, as there are way too many things to talk about with 10-15 minutes to record. (I really did try to whittle it down to under 10.)

This is me going on record that I’ve tried my best to showcase my original contributions to learning this and have made sure to comment out code or omit assets that haven’t been created by me. Ones left in are solely due to time constraints mentioned above. Please let me know if you have any specific concerns of credits of which I may be missing, and I will be more than happy to add them into this report/README section.

I will certainly return to this in future. Be sure to keep a look out!

Many thanks, and take care ^^

#### Other Helpful Links:
Youtube Explanation: https://youtu.be/qFDvk-AOLkU  
Git repository: https://github.com/KJEKJE/comp3015_referral  
OneDrive (solely for marking availability): [COMP3015 referral](https://liveplymouthac-my.sharepoint.com/:w:/r/personal/kjellon_morris_students_plymouth_ac_uk/Documents/COMP3015%20referral/Feature%20Declaration.docx?d=weebe9481e82f45e8951d38b740b92857&csf=1&web=1&e=FohAgH)

[written on 21-8-23]
