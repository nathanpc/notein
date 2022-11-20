package com.innoveworkshop.notein;

import java.util.ArrayList;
import java.util.List;

/**
 * Abstraction of a category in a workspace, or in other words, a folder.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */
public class Category {
	private String path;

	/**
	 * Creates a category based on a path relative to the workspace.
	 *
	 * @param path Path relative to the workspace where the category folder lives.
	 */
	public Category(String path) {
		setPath(path);
	}

	/**
	 * Gets the category folder name.
	 *
	 * @return Category folder name.
	 */
	public String getTitle() {
		// TODO: Return the last part of the path.
		return null;
	}

	/**
	 * Sets the category folder name.
	 *
	 * @param title New category folder name.
	 */
	public void setTitle(String title) {
		// TODO: Check if the title is valid for a file system.
		// TODO: Rename the folder.
	}

	/**
	 * Gets the category path relative to the workspace it's in.
	 *
	 * @return Note path.
	 */
	public String getPath() {
		return this.path;
	}

	/**
	 * Sets the note path relative to the workspace it's in.
	 *
	 * @param path New note path.
	 */
	public void setPath(String path) {
		// TODO: Check if it's a valid path.
		this.path = path;
	}

	/**
	 * Gets a list of the subcategories/folders inside of this category/folder.
	 *
	 * @return List of subcategories inside of this category.
	 */
	public List<Category> getSubCategories() {
		ArrayList<Category> subCategories = new ArrayList<Category>();

		// TODO: go through the directories and populate the array with categories.

		return subCategories;
	}

	/**
	 * Gets a list of the notes inside of this category/folder.
	 *
	 * @return List of notes inside of this category.
	 */
	public List<Note> getNotes() {
		ArrayList<Note> notes = new ArrayList<Note>();

		// TODO: go through the directories and populate the array with notes.

		return notes;
	}
}
