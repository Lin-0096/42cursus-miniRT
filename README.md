<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/minirtm.png" alt="42 miniRT badge">
  <p><a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a> core curriculum project</p>
  <h1>miniRT</h1>
</div>

`miniRT` requires me to build a **basic ray tracer in C**, capable of parsing a scene file and generating a realistic image by simulating light rays and their interaction with objects.

---

## Key Features

- Parses `.rt` scene description files containing camera, lights, and primitive objects (sphere, plane, cylinder, etc.)
- Implements core ray‑tracing pipeline: ray generation, object intersection, shading (diffuse, specular), shadows, reflections and refractions (bonus)
- Handles basic mathematics behind graphics: vectors, dot/cross products, normalization, solving intersection equations
- Outputs an image (e.g., BMP or PNG) which you can view as a rendered 3D scene

---

## Core Technical Skills

- 3D geometry and vector math for ray‑object intersection
- Parsing textual scene descriptions and building scene graphs
- Implementing the rendering loop that computes pixel color by casting rays
- Memory and resource management in C (allocations, error handling, cleanup)
- Optional advanced features: anti‑aliasing, bump mapping, texture mapping, reflections/refractions

---

## How to Run

```bash
git clone https://github.com/Lin-0096/42cursus-miniRT.git
cd 42cursus-miniRT
make
./miniRT scenes/(any file here or create your own scene)
```

---

## Learning Outcomes

- Practiced **vector math**, **geometry**, and **graphics algorithms**
- Gained experience in **parsing**, **image generation**, and **software architecture** for rendering
- Strengthened ability to write clean code, handle edge cases, and manage memory in more complex C projects

---

**Developed by [Lin-0096](https://github.com/Lin-0096)**
