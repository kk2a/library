# Repository instructions

## Commits and pushes

- Commits created by Codex must include `Co-authored-by: Codex <codex@openai.com>`.
- During development, keep commits local and avoid pushing to the remote repository.
- Push only when the implementation and relevant verification are complete and the branch is ready to be merged.
- Before pushing, run the relevant local tests and confirm that the worktree is clean apart from intended changes.

## Japanese writing

- In Japanese prose, use the full-width comma `，` and full-width period `．` instead of `、` and `。`.

## API documentation

- Every Doxygen comment for a public API must include `@brief`.
- Keep Doxygen comments concise. Put algorithms, constraints, correctness arguments, and complexity analysis in the Markdown file associated through `documentation_of`.
- Write `documentation_of` as an absolute path from the repository root, using the `//path/to/file` syntax.
- Add an `@see` URL from each Doxygen comment to the corresponding section of the generated library documentation.
- When one source file defines multiple public functions, organize its Markdown documentation into sections with stable anchors for those functions.
- When a Markdown document mentions another library function, link its name to the corresponding generated library documentation page.
- In each function section, use subsections corresponding to `Declaration`, `Overview`, `Algorithm`, `Correctness`, `Constraints`, and `Complexity` in this order, localized to the document's language. Omit a subsection when it does not apply.
