package com.innoveworkshop.notein;

import java.util.ArrayList;
import java.util.List;

import com.innoveworkshop.notein.data.NoteFormat;

/**
 * Abstraction of a note in a workspace.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */
public class Note {
	private NoteFormat format;
	private ArrayList<String> attributes;
	private String content;
	private String path;

	/**
	 * Creates a blank note object.
	 */
	public Note() {
		// Setup some defaults and ensure the object is invalid in the case
		// someone tries to save this.
		this.format = NoteFormat.PLAIN;
		this.attributes = new ArrayList<String>();
		this.content = "";
		this.path = null;
	}

	/**
	 * Creates a note object given a path relative to the workspace root.
	 *
	 * @param path Path to the note relative to the workspace it's in.
	 */
	public Note(String path) {
		this();
		setPath(path);
	}

	/**
	 * Gets the note title.
	 *
	 * @return Note title.
	 */
	public String getTitle() {
		// TODO: Extract this from the path.
		return null;
	}

	/**
	 * Sets the note title.
	 *
	 * @param title New note title.
	 */
	public void setTitle(String title) {
		// TODO: Check if valid for a path.
		// TODO: Rename the file in path and apply it to the file system.
	}

	/**
	 * Gets the note format that the content is using.
	 *
	 * @return Note content format.
	 */
	public NoteFormat getFormat() {
		return this.format;
	}

	/**
	 * Sets the note format that the content is using.
	 *
	 * @param format New note content format.
	 */
	public void setFormat(NoteFormat format) {
		// TODO: Change the extension in the path of the note.
		this.format = format;
	}

	/**
	 * Gets the note attributes.
	 *
	 * @return Note attributes.
	 */
	public List<String> getAttributes() {
		// TODO: Lazy load the attributes.
		return this.attributes;
	}

	/**
	 * Sets the note attributes.
	 *
	 * @param attributes New note attributes.
	 */
	public void setAttributes(List<String> attributes) {
		this.attributes = new ArrayList<String>(attributes);
	}

	/**
	 * Gets the note content.
	 *
	 * @return Note content.
	 */
	public String getContent() {
		// TODO: Lazy load this.
		return this.content;
	}

	/**
	 * Sets the note content.
	 *
	 * @param content New note content.
	 */
	public void setContent(String content) {
		this.content = content;
	}

	/**
	 * Gets the note path relative to the workspace it's in.
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
		// TODO: Extract the format from the path.
		this.path = path;
	}

	@Override
	public String toString() {
		return getTitle() + "\n\n" + getContent();
	}
}
