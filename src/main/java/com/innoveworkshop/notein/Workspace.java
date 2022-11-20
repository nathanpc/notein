package com.innoveworkshop.notein;

import java.util.ArrayList;
import java.util.List;

/**
 * Abstraction of a NoteIn workspace, which is just a folder that contains all
 * of your notes.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */
public class Workspace {
	private String basePath;

	/**
	 * Creates a workspace object given a base path for the notes.
	 *
	 * @param basePath Base path to set as the root of the workspace.
	 */
	public Workspace(String basePath) {
		setBasePath(basePath);
	}

	/**
	 * Gets the list of notes available in this workspace all squashed into a
	 * single list ignoring their hierarchy.
	 *
	 * @return List of all the notes in this workspace.
	 */
	public List<Note> getNotesList() {
		ArrayList<Note> notes = new ArrayList<Note>();

		// TODO: go through the directories and populate the array with notes.

		return notes;
	}

	/**
	 * Gets the base path (root) of a workspace filled with notes.
	 *
	 * @return Base path of the NoteIn workspace.
	 */
	public String getBasePath() {
		return this.basePath;
	}

	/**
	 * Sets the workspace root/base path.
	 *
	 * @param basePath Base path of the NoteIn workspace.
	 */
	public void setBasePath(String basePath) {
		this.basePath = basePath;
	}
}
