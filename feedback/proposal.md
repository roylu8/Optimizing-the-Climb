### Regrade

Sophisticated (100%)

Dijkstra's is pretty fast, especially on a sparse graph like ours (|E| <= 8 |V| = O(|V|)). On a typical laptop (1-3GHz), C++ Dijkstra's should comfortably process 10^6 nodes in \~1 second. Let's try to implement and benchmark the time before ruling out large maps. Also, we should get an initial implementation early since we might need to adjust the energy expenditure formula.

OpenGL is a great plus (again, not required but it'd be awesome to see). To start with (or determining its viability), take a look at one of many OpenGL tutorials on terrain rendering from heightmaps (tessellation/triangulation.

I'm excited to see how the most energy efficient paths would look like.

By the way, there are still some remaining texts related to hydraulic erosion from previous iteration (e.g. Section 2c).

### Grade

Incomplete (0%)

Must resubmit!

No penalty after resubmission.

### Checklist

Leading question
- [x] Interesting question or expected result
- [x] How the dataset and algorithms will answer this

Dataset
- [x] Data format (PNG)
- [ ] Acquire
- [x] Process (`fstream` )
- [x] Store (2D array)
- [x] Data correction for potential errors (validate luminance, check bound)

Algorithm
- [ ] One graph traversal
  - [ ] Input and output
  - [ ] Run-time efficiency
- [ ] One algorithm in class
  - [ ] Input and output
  - [ ] Run-time efficiency
- [ ] One algorithm not in class
  - [ ] Input and output
  - [ ] Run-time efficiency

Timeline
- [x] Reasonable date on every major benchmark.

### Comments

Very exciting project direction! However, although the professors also find the project interesting, the selected algorithm isn't considered a graph algorithm. Please pivot the project to include graph algorithms ([examples](https://docs.google.com/document/d/10VL05FxUCQZMLb_jQfsfOMNR56ecxy0aIaqPH6KumBQ/edit)).

A few comments on other areas:
- Where/how would you acquire the heightmap(s)?
- There should be O(nm) triangles generated. For example, we can generate 6 triangles around each pixel, totaling to O(6nm) = O(nm). 
- Timeline dates are reasonable as important dates for milestones. In reality, I'd recommend starting on tasks as soon as they are unblocked. Many of them are tricky to write and more tricky to test.

Please feel free to contact me if you have any further question or need clarification. Keep up the great work!