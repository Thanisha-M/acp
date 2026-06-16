const education = [
  ["REVA University", "B.Tech in Computer Science Engineering (AI & ML)", "Currently enrolled"],
  ["East West Pre-University College", "Grade 11 & 12", "92%"],
  ["Air Force School Yelahanka", "Schooling", "85%"]
];

const tools = [
  ["AI", "ChatGPT"],
  ["Py", "Python"],
  ["UI", "Canva"],
  ["Doc", "Google Docs"],
  ["Git", "GitHub"],
  ["Web", "Vercel"]
];

const skills = [
  "Frontend Development",
  "Presentation Design",
  "Report Writing",
  "Coding Assignments",
  "Project Documentation"
];

const achievements = [
  "Wadhwani Entrepreneurship Certification",
  "Python for Data Science",
  "Active participation in innovation-focused engineering work"
];

const projects = [
  {
    title: "FocusSpace",
    purpose: "Productivity Tool",
    features: ["Website Blocking UI", "Notification Control", "Focus Timer Dashboard"],
    image: "/focusspace-preview.svg",
    href: "https://github.com/sapana-learner/website-blocker-backend",
    linkLabel: "GitHub Repository"
  },
  {
    title: "Vera",
    purpose: "Psychometric Analysis Tool",
    features: ["Assessment Enclave screenshots", "Behavior Metrics Dashboard", "Text and visual reports"],
    image: "/vera-preview.svg",
    href: "https://psychometric-analysis-demo.vercel.app",
    linkLabel: "Live Demo"
  },
  {
    title: "Altheria Gateway",
    purpose: "Forensic Tactical Simulation System",
    features: ["Login Gateway", "Command Hub Dashboard", "Case Verification Panel"],
    image: "/altheria-preview.svg"
  }
];

function Section({ id, title, children, className = "" }) {
  return (
    <section id={id} className={`section-shell py-16 md:py-20 ${className}`}>
      <h2 className="mb-8 text-3xl font-bold text-white">{title}</h2>
      {children}
    </section>
  );
}

export default function Home() {
  return (
    <main className="min-h-screen overflow-hidden">
      <nav className="fixed left-0 right-0 top-0 z-50 border-b border-white/10 bg-[#07111f]/75 backdrop-blur-xl">
        <div className="section-shell flex h-16 items-center justify-between">
          <a href="#home" className="font-bold text-white">
            Thanisha <span className="accent-text">M</span>
          </a>
          <div className="hidden gap-5 text-sm font-semibold text-slate-300 md:flex">
            <a href="#education" className="transition hover:text-white">Education</a>
            <a href="#tools" className="transition hover:text-white">Tools</a>
            <a href="#projects" className="transition hover:text-white">Projects</a>
            <a href="#contact" className="transition hover:text-white">Contact</a>
          </div>
        </div>
      </nav>

      <section id="home" className="section-shell grid min-h-screen items-center gap-10 pb-16 pt-28 md:grid-cols-[0.9fr_1.1fr]">
        <div className="mx-auto w-full max-w-sm">
          <div className="glass rounded-[2rem] p-4 shadow-glow">
            <object
              data="/thanisha-photo.jpeg"
              type="image/jpeg"
              aria-label="Thanisha M photo"
              className="aspect-[4/5] w-full overflow-hidden rounded-[1.5rem] object-cover shadow-2xl"
            >
              <img
                src="/avatar.svg"
                alt="Thanisha M avatar"
                className="aspect-[4/5] w-full rounded-[1.5rem] object-cover shadow-2xl"
              />
            </object>
          </div>
        </div>

        <div className="text-center md:text-left">
          <p className="mb-4 inline-flex rounded-full border border-teal-300/25 bg-teal-300/10 px-4 py-2 text-sm font-semibold text-teal-100">
            AI & ML Engineering Student
          </p>
          <h1 className="text-4xl font-bold text-white md:text-6xl">Thanisha M</h1>
          <p className="mt-5 text-xl font-semibold leading-8 text-slate-200 md:text-2xl">
            AI & ML Engineering Student | Problem Solver | Builder
          </p>
          <p className="mx-auto mt-5 max-w-2xl text-base leading-8 text-slate-300 md:mx-0 md:text-lg">
            I build useful AI-powered applications, clean project documentation, and polished technical
            presentations with a practical, problem-solving mindset.
          </p>
          <a
            href="#projects"
            className="mt-8 inline-flex rounded-full bg-gradient-to-r from-teal-300 via-sky-300 to-purple-300 px-7 py-3 font-bold text-slate-950 shadow-glow transition hover:-translate-y-1"
          >
            View My Work
          </a>
        </div>
      </section>

      <Section id="education" title="Education">
        <div className="grid gap-5 md:grid-cols-3">
          {education.map(([school, course, score]) => (
            <article key={school} className="glass rounded-2xl p-6 transition hover:-translate-y-1">
              <h3 className="text-2xl font-bold text-white">{school}</h3>
              <p className="mt-4 text-lg font-semibold text-slate-200">{course}</p>
              <p className="mt-3 text-base font-bold text-teal-200">{score}</p>
            </article>
          ))}
        </div>
      </Section>

      <section id="tools" className="section-shell py-16 md:py-20">
        <h2 className="mb-8 text-2xl font-semibold text-white">Tools & Workspaces</h2>
        <div className="grid gap-4 sm:grid-cols-2 lg:grid-cols-3">
          {tools.map(([icon, tool]) => (
            <div key={tool} className="glass flex items-center gap-4 rounded-2xl p-5 transition hover:-translate-y-1">
              <span className="flex h-12 w-12 items-center justify-center rounded-2xl bg-white text-lg font-black text-slate-950">
                {icon}
              </span>
              <span className="text-xl font-bold text-white">{tool}</span>
            </div>
          ))}
        </div>
      </section>

      <section id="skills" className="section-shell py-16 md:py-20">
        <h2 className="mb-8 text-2xl font-semibold text-white">Skills</h2>
        <ul className="grid gap-4 md:grid-cols-2">
          {skills.map((skill) => (
            <li key={skill} className="glass rounded-2xl p-5 text-lg font-semibold text-slate-100">
              <span className="mr-3 text-teal-200">•</span>
              {skill}
            </li>
          ))}
        </ul>
      </section>

      <Section id="experience" title="Experience">
        <article className="glass rounded-3xl p-8 text-center md:p-12">
          <h3 className="text-center text-2xl font-bold text-white md:text-4xl">Grand Challenge Course</h3>
          <p className="mx-auto mt-5 max-w-3xl text-lg leading-8 text-slate-300">
            Focused on solving real-world problems through innovation, teamwork, and engineering execution.
          </p>
        </article>
      </Section>

      <Section id="achievements" title="Achievements & Milestones">
        <div className="grid gap-4 md:grid-cols-3">
          {achievements.map((item) => (
            <div key={item} className="glass rounded-2xl p-6 text-lg font-semibold text-slate-100">
              {item}
            </div>
          ))}
        </div>
      </Section>

      <Section id="projects" title="Featured Projects">
        <div className="grid gap-6 lg:grid-cols-3">
          {projects.map((project) => (
            <article key={project.title} className="glass overflow-hidden rounded-3xl transition hover:-translate-y-2">
              <img src={project.image} alt={`${project.title} preview`} className="aspect-video w-full object-cover" />
              <div className="p-6">
                <h3 className="text-2xl font-bold text-white">{project.title}</h3>
                <p className="mt-2 text-lg font-semibold text-teal-200">{project.purpose}</p>
                <ul className="mt-5 space-y-3 text-base leading-7 text-slate-300">
                  {project.features.map((feature) => (
                    <li key={feature}>• {feature}</li>
                  ))}
                </ul>
                {project.href ? (
                  <a
                    href={project.href}
                    target="_blank"
                    rel="noreferrer"
                    className="mt-6 inline-flex rounded-full border border-white/15 px-5 py-3 font-bold text-white transition hover:bg-white hover:text-slate-950"
                  >
                    {project.linkLabel}
                  </a>
                ) : null}
              </div>
            </article>
          ))}
        </div>
      </Section>

      <Section id="contact" title="Contact">
        <div className="glass grid gap-3 rounded-3xl p-6 text-lg font-semibold md:grid-cols-3">
          <a className="rounded-2xl bg-white/8 p-4 text-white transition hover:text-teal-200" href="mailto:thanisha2007@gmail.com">
            Email: thanisha2007@gmail.com
          </a>
          <a className="rounded-2xl bg-white/8 p-4 text-white transition hover:text-teal-200" href="https://github.com/Thanisha-M" target="_blank" rel="noreferrer">
            GitHub: github.com/Thanisha-M
          </a>
          <a className="rounded-2xl bg-white/8 p-4 text-white transition hover:text-teal-200" href="https://www.linkedin.com/in/thanisha-m-839787384" target="_blank" rel="noreferrer">
            LinkedIn: thanisha-m-839787384
          </a>
        </div>
      </Section>
    </main>
  );
}
