# How to Submit Assignments

Welcome! This guide walks you through submitting your weekly assignments for this course via GitHub.

---

## Prerequisites

- A [GitHub account](https://github.com)
- Git installed on your laptop ([Download Git](https://git-scm.com/downloads))
- Basic familiarity with the terminal

---

## One-Time Setup

### Step 1 — Fork the repository

1. Go to the main course repository on GitHub
2. Click the **Fork** button (top-right corner)
3. This creates your own personal copy of the repo under your GitHub account

### Step 2 — Clone your fork

Open your terminal and run:

```bash
git clone https://github.com/adityasanapala/SoC-DSA.git
cd SoC-DSA
```

Replace `YOUR_GITHUB_USERNAME` accordingly.

### Step 3 — Create your branch

Create a branch named **exactly** as your roll number (e.g. `23b0001`):

```bash
git checkout -b 23b0001
```

> ⚠️ Your branch name must match your roll number exactly — lowercase, no spaces.  
> The format is: two digits + the letter `b` + your number (e.g. `23b0001`).  
> This is how your submissions are identified — get this right!

---

## Submitting Assignments

You can submit one week at a time, or multiple weeks in a single PR — both are fine.

### Step 1 — Add your solutions

Place your solution files inside the relevant week folder. For example:

```
Week 1/my_solution.py
Week 2/my_solution.py
Week 2/helper.py
```

> ⚠️ Do **not** rename or delete the existing files in the week folders (like `README.md`).  
> Only **add** your own new files.

### Step 2 — Commit your work

```bash
git add .
git commit -m "Submit Week 1"
```

### Step 3 — Push to your fork

```bash
git push origin 23b0001
```

(Replace `23b0001` with your actual roll number.)

### Step 4 — Open a Pull Request

1. Go to your fork on GitHub
2. You'll see a banner saying **"Compare & pull request"** — click it
3. Make sure the PR is targeted at the **main course repo's `main` branch** (not your own fork)
4. Give your PR a clear title like: `Week 1 submission - 23b0001`
5. Click **Create pull request**

---

## What happens next

Once your PR is reviewed and approved by the instructor:

- Your files are automatically moved to `submissions/23b0001/Week 1/`
- The bot will post a comment on your PR confirming exactly which files were received
- The week folders in the main repo are restored to their original state

---

## Updating a submission before it's merged

If you need to fix something after opening a PR (but **before** it's merged), just push more commits to the same branch — the PR updates automatically:

```bash
# edit your file, then:
git add .
git commit -m "Fix Week 1 solution"
git push origin 23b0001
```

---

## Common mistakes to avoid

| ❌ Don't do this | ✅ Do this instead |
|---|---|
| Name your branch anything other than your roll number | Use exactly your roll number, e.g. `23b0001` |
| Submit files outside `Week */` folders | Put files inside `Week 1/`, `Week 2/`, etc. |
| Delete or rename existing week files | Only **add** your own new files |
| Open a PR to your own fork | Open the PR to the **main course repo** |
| Use uppercase or spaces in your branch name | Keep it lowercase, no spaces |

---

## Need help?

If something isn't working, open an issue on the course repo or reach out to the instructor directly.