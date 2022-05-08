# Final Project Grade

Awesome work, everyone! I hope it was a rewarding experience for you all :D

Here are some parts of the final project grade (apart from contract, proposal, and midproject checkin).

If you would like to showcase your work, feel free to clone this repository and host it on your personal git account (github-dev.cs.illinois.edu is being retired soon).

## Development Log

### Grade 

Sophisticated (100%)

Development Log (5 pts)
- [x] >= 4 development logs

### Comments

______________________________________________________________

## Presentation
### Content Grade

Sophisticated (100%)

Final Presentation Content (10 pts)
- [x] A short summary of the goals set for the project and a statement of whether the goals were met.
- [x] Some highlights of the development process (dataset, major design choices, and testing)
- [x] Results of each method
- [x] Concluding thoughts (what was learned and what you would do next)

### Skills Grade

Sophisticated (100%)

Final Presentation Skills (5 pts)
- [x] Roughly equal responsibilities
- [x] Appropriate and understandable visual aids

### Comments

Great presentation! Espcially I like that you include both technical and non-technical (your product's impacts, challenges, etc.) aspects.

By the way, the video I watched is https://www.youtube.com/watch?v=vRzmfvQZMzo. The one linked in README.md is missing the audio.

______________________________________________________________

## Written Report
### Grade

Competent (90%)

Written Report (5 pts)
- [x] There are clear descriptions, figures, or tables of each method's output on the full target dataset.
- [x] Projects findings

### Comments

An output from A\* is also missing (more discussion/observation would be nice too). It would be interesting to read about how you design the energy function. Maybe we can correct some artifacts in the shortest paths too (they tend to go straight down at the last segment).

## README

### Grade

Sophisticated (100%)

Readme (5 pts)
- [x] The linkage and location of all major code, data, results, and deliverable files
- [x] The necessary commands to run the assignment, include instructions for selecting the input dataset and output location
- [x] Instructions on how to reproduce the tests

### Comments

Well written. All instructions are clear when trying it out.

______________________________________________________________

## Code

### Goals Grade

Partly Competent (80%)

Code Goals (30 pts)
- [ ] All methods listed in goals were successfully developed
- [x] All algorithms can be run on the full target dataset
- [x] All algorithms are thoroughly tested

### Execution Grade

Sophisticated (100%)

Code Execution (5 pts)
- [x] All methods and tests can be run
- [x] Ability to alter or adjust the input data and output location

### Efficiency Grade

Sophisticated (100%)

Code Efficiency (5 pts)
- [x] Code adheres to the expected Big O (since the graph is a grid so `|E| = O(|V|)`)
- [x] There is no obvious inefficiency
- [x] Complete on target datasets

### Organization Grade

Competent (90%)

Code Organization (5 pts)
- [ ] Code is human-readable
- [ ] Unnecessary or obsolete code is completely absent

### Comments

Overall the implementation looks great! The test covers verifiable cases as well as larger inputs. Some refactoring could improve the quality though, e.g. using direction enums, consolidating cases based on image border, structuring class hierarchy better, avoiding "global" private fields.

Mainly missing BFS unfortunately.

The source code lacks comments and still contains some commented-out lines. 
